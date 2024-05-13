import cv2
from ultralytics import YOLO
from collections import defaultdict
import numpy as np

# ? Daqui até ...

# Parâmetros da câmera (preencha com os valores da sua câmera)
# focal_length = 640  # Substitua com a distância focal da sua câmera (em pixels)
# known_object_width = (
#     10  # Substitua com a largura real do objeto em centímetros (ou outra unidade)
# )

# ? ... aqui é o cálculo da distância até o objeto

cap = cv2.VideoCapture(1)

# Carregue o modelo YOLO
model = YOLO("runs/detect/train21/weights/best.pt")

# Dicionário para rastrear IDs e histórico de posições
track_history = defaultdict(lambda: [])

# Variáveis de controle
seguir = True
deixar_rastro = True

while True:
    # ?Aqui : Capture a imagem do vídeo

    success, img = cap.read()

    # ? ... Até aqui+
    if success:
        # Processamento com YOLO
        if seguir:
            results = model.track(
                img,
                persist=True,
                conf=0.35,
                imgsz=96,
                iou=0.3,
                max_det=2,
                stream_buffer=True,
                batch=-1,
                rect=True,
                # plots=True, # teste para plotar num gráfico a probabilidade de achar um cone :)
            )
        else:
            results = model(img)

        # Processamento dos resultados
        for result in results:
            # Visualização dos resultados na imagem
            img = result.plot()

            # Rastreamento e estimativa de distância
            if seguir and deixar_rastro:
                try:
                    # Obter caixas
                    boxes = result.boxes.xywh.cpu()

                    # Traçar rastreamento
                    for box, track_id in zip(boxes):
                        x, y, w, h = box

                        # ? Daqui até ...

                        # # Estimar distância usando largura do objeto e razão de triângulos similares
                        # distance = (known_object_width * focal_length) / w
                        # print(f"Distância estimada para o objeto: {distance:.2f} cm")

                        # ? ... aqui é o cálculo da distância até o objeto

                        # Calcular a posição do objeto em relação ao centro da tela
                        center_x = (x + w / 2) / img.shape[1]
                        center_y = (y + h / 2) / img.shape[0]
                        offset_x = (
                            center_x - 0.68
                        )  # Centro da tela na coordenada x é 0.68
                        offset_y = (
                            center_y - 0.8
                        )  # Centro da tela na coordenada y é 0.8

                        print(
                            f"Posição do objeto em relação ao centro da tela: (x={offset_x:.2f}, y={offset_y:.2f})"
                        )

                except Exception as e:
                    print(f"Erro no rastreamento: {e}")

    # ? Aqui exibe imagens como resultado...
    # Exibir imagem com resultados
    cv2.imshow("Tela", img)

    # ? ... até aqui

    # Tecla 'q' para sair
    k = cv2.waitKey(1)
    if k == ord("q"):
        break

# Liberar recursos
cap.release()
cv2.destroyAllWindows()
print("Desligando...")
