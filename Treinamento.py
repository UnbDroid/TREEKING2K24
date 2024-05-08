from ultralytics import YOLO

# ? Quando você rodar esse código, ele começará a treinar com o modelo que desejou
# ? por exemplo o modelo nano, para mais informações : https://docs.ultralytics.com/models/yolov8/#performance-metrics


def main():

    model = YOLO("yolov8n.yaml")  #! Você muda aqui qual modelo vai querer usar

    model.train(
        data="data.yaml", epochs=100, amp=False, batch=-1
    )  # *Train settings : https://docs.ultralytics.com/modes/train/#train-settings
    metrics = model.val()  #


if __name__ == "__main__":
    # freeze_support() #! caso dê erro pesquise por freeze_support()
    main()
