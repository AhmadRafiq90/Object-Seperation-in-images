# Object Separation in Images

This project focuses on separating distinct objects from the background in an image. The given image has a size of 512x512 pixels, where the background is represented by a pixel value of 0 (black) and the objects are represented by a pixel value of 255 (white). The goal is to separate each object from the rest of the image.

## Algorithm

There are two methods provided to separate the objects from the background: row-wise traversal and column-wise traversal. Both methods involve creating a blank new image where the separated objects will be placed. The new image will have all regions black except for the area of the separated object.

### Method 1: Row-wise Traversal

In this method, a queue is used to process the pixels. The algorithm follows these steps:

1. Create a blank image of the same size as the input image.
2. Find the starting point of the object, which is the first pixel with a value of 255.
3. Add the starting pixel location to the queue.
4. While the queue is not empty, remove a pixel location from the queue.
5. Set the corresponding pixel in the new blank image to 255.
6. Check all neighboring pixels of the removed pixel that have a value of 255.
7. Add the neighboring pixel locations to the queue if they have not been processed before.
8. If a pixel has already been processed by the queue, it is not added again.
9. Repeat steps 4-8 until the queue is empty.
10. The resulting new blank image will have the object separated from the rest of the image.

### Method 2: Column-wise Traversal

In this method, a stack is used to process the pixels. The algorithm follows these steps:

1. Create a blank image of the same size as the input image.
2. Find the starting point of the object, which is the first pixel with a value of 255.
3. Add the starting pixel location to the stack.
4. While the stack is not empty, remove a pixel location from the stack.
5. Set the corresponding pixel in the new blank image to 255.
6. Check all neighboring pixels of the removed pixel that have a value of 255.
7. Add the neighboring pixel locations to the stack if they have not been processed before.
8. If a pixel has already been processed by the stack, it is not added again.
9. Repeat steps 4-8 until the stack is empty.
10. The resulting new blank image will have the object separated from the rest of the image.

## Usage

To use this project, follow these steps:

1. Clone the repository.
2. Ensure that the required dependencies for image processing are installed.
3. Provide the input image of size 512x512 pixels, where the objects are clearly distinct and represented as white (255) against a black (0) background.
4. Choose either the row-wise traversal method or the column-wise traversal method.
5. Run the corresponding script for the chosen method, providing the necessary input.
6. The resulting new blank image with the separated object will be generated and saved.

Note: Ensure that the input image is properly formatted and meets the specified requirements.

## Results

The resulting new blank image with the separated object will be saved in the project directory. Please refer to the generated image for the object separated from the rest of the image.

## License

This project is licensed under the [MIT License](LICENSE).

Feel free to contribute, modify, or distribute this codebase following the terms of the license.

## Acknowledgments

- This project utilizes various image processing techniques and algorithms.
- Credits to the contributors and developers of the used libraries and dependencies.
