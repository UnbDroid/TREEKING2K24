#!/usr/bin/env bash

source "/home/caldo/Documents/Droid/VirtEnvTrekking/bin/activate" 
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/caldo/Documents/Droid/VirtEnvTrekking/lib/python3.10/site-packages/nvidia/nvtx/lib
python3 "/home/caldo/Documents/Droid/TREEKING2K24/Código Visão/ModelosDeTeste/Distancia_Posicionamento.py"
