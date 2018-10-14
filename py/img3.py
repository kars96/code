import os
from skimage import io, data, color   
import skimage
import os
print(skimage.data_dir)
filename=os.path.join(skimage.data_dir,"camera.png")
camera=io.imread(filename)
print(color.guess_spatial_dimensions(camera))
# io.imshow(camera)
# io.show()