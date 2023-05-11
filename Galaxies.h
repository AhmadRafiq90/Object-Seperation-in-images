#pragma once
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include "Stack.h"
#include <iostream>
using namespace std;
using namespace cv;

int get_value(Mat& obj, int i, int j)
{
	return int(obj.at<uchar>(i, j));
}

template <class T>
void enqueue_neighbours(int** original, int** labelled, T& s1, int row, int col)
{
	for (int i = col - 1; i < (col - 1) + 3; i++)
	{
		for (int j = row - 1; j < (row - 1) + 3; j++)
		{
			if (i == col && j == row)
				continue;
			else if (original[j][i] == 255)
			{
				s1.push(j, i);
				original[j][i] = 0, labelled[j][i] = 255;
			}
		}
	}
}
// Returns total number of objects in an image.
// Can be performed using both stacks and queues. This is controlled by passing the required data structure as a parameter.
// Takes a path as string where the new images of every distinct object should be stored.

template <class T>
int find_galaxies(Mat& obj, T DataStruct, string path)
{
	int count = 1;
	const int rows = obj.rows, cols = obj.cols;
	Mat* img = new Mat(rows, cols, obj.type());
	// Making copy of original image.

	int** original_img = new int* [rows];
	for (int i = 0; i < rows; i++)
		original_img[i] = new int[cols];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			original_img[i][j] = get_value(obj, i, j);
		}
	}

	int no_of_components = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (original_img[i][j] == 255)
			{
				img = new Mat(obj.rows, obj.cols, obj.type());

				int** labelled_img = new int* [rows];
				for (int i = 0; i < rows; i++)
					labelled_img[i] = new int[cols] {};

				DataStruct.Enqueue(i, j);
				while (!BFS.isEmpty())
				{
					Pixel front = DataStruct.top();
					int r = front.row, c = front.col;
					DataStruct.Dequeue();
					enqueue_neighbours(original_img, labelled_img, BFS, r, c);
					labelled_img[r][c] = 255, original_img[r][c] = 0;
				}
				for (int i = 0; i < rows; i++)
				{
					for (int j = 0; j < cols; j++)
						img->at<uchar>(i, j) = labelled_img[i][j];
				}
				imshow("Component number " + to_string(count), *img);
				imwrite(path + to_string(count++) + ".png", *img);
				waitKey();
				no_of_components++;
			}
		}
	}
	return no_of_components;
}
