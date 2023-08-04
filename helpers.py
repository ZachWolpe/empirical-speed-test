
import numpy as np
import shutil
import os

def clear_directory(dir='results'):
    """
    Clear directory.
    """
    if os.path.exists(dir):
        shutil.rmtree(dir)
    os.makedirs(dir)