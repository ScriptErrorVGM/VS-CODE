import os
import random
from PIL import Image
imgExtension = ["jpg","webp","png", "jpeg" ] #Image Extensions to be chosen from
allImages = list()



def chooseRandomImage(directory="C:/Users/Grigory/Desktop/fus_rae/"):
    for img in os.listdir(directory): #Lists all files
        ext = img.split(".")[len(img.split(".")) - 1]
        if (ext in imgExtension):
            allImages.append(img)
    choice = random.randint(0, len(allImages) - 1)
    chosenImage = allImages[choice] #Do Whatever you want with the image file
    return chosenImage


randomImage = chooseRandomImage()
print(randomImage)
img = Image.open("C:/Users/Grigory/Desktop/fus_rae/"+randomImage)
print(img)
img.show()