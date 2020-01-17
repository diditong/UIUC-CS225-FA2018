/**
 * @file maze.h
 * @author Soohyuck Cho
 */
#ifndef _MAZE_H_
#define _MAZE_H_

#include "./cs225/PNG.h"
#include "./cs225/HSLAPixel.h"
#include "dsets.h"
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
using namespace cs225;

class SquareMaze {
public:
    /**
     * No-parameter constructor.
     * Creates an empty maze.
     */
    SquareMaze();

    /**
     * Makes a new SquareMaze of the given height and width.
     * Select random walls to delete without creating a cycle, until there are
     * no more walls that could be deleted without creating a cycle.
     * Do not delete walls on the perimeter of the grid.
     *
     * @param width: The width of the SquareMaze(number of cells).
     * @param height: The height of the SquareMaze(number of cells).
     *
     * @hint Store 2 bits per square: the "down" and "right" walls.
     * The finished maze is always a tree of corridors.
     */
    void makeMaze(int width, int height);

    /**
     * Determine whether it is possible to travel in the given direction from the
     * coordinate (x, y).
     *
     * @param x: The x coordinate of the current cell.
     * @param y: The y coordinate of the current cell.
     * @param dir: The desired direction to move from the current cell.
     * @return True if you can travel in the specified direction, false otherwise.
     *
     * @note: dir = 0 : +x, dir = 1 : +y, dir = 2 : -x, dir = 3 : -y.
     */
    bool canTravel(int x, int y, int dir) const;

    /**
     * Sets whether or not the specified wall exists.
     *
     * @param x: The x coordinate of the current cell.
     * @param y: The y coordinate of the current cell.
     * @param dir: Either 0(right) or 1(down).
     * @param exists: True if setting the wall to exist, false otherwise.
     */
    void setWall(int x, int y, int dir, bool exists);

    /**
     * Solves this SquareMaze.
     *
     * @return True if you can travel in the specified direction, false otherwise.
     *
     * @note: If multiple paths of maximum length exist, use the one with the
     * destination cell that has the smallest x value.
     *
     * @hint This function should run in time linear in the number of cells in the maze.
     */
    vector<int> solveMaze();

    /**
     * Draws the maze without the solution.
     *
     * @return A PNG of the unsolved SquareMaze.
     *
     * @note: First, create a new PNG. Set the dimensions of the PNG to (width*10+1,height*10+1).
     * Blacken the entire topmost row and leftmost column of pixels, except the
     * entrance (1,0) through (9,0). For each square in the maze, call its maze coordinates (x,y).
     * If the right wall exists, then blacken the pixels with coordinates ((x+1)*10,y*10+k)
     * for k from 0 to 10. If the bottom wall exists, then blacken the pixels
     * with coordinates (x*10+k, (y+1)*10) for k from 0 to 10.
     *
     * @note: The resulting PNG will look like the sample image, except there
     * will be no exit from the maze and the red line will be missing.
     */
    PNG * drawMaze() const;

    /**
     * This function calls drawMaze, then solveMaze; it modifies the PNG from
     * drawMaze to show the solution vector and the exit.
     *
     * @return A PNG of the solved SquareMaze.
     *
     * @note: Start at pixel (5,5). Each direction in the solution vector corresponds
     * to a trail of 11 red pixels in the given direction. If the first step is
     * downward, color pixels (5,5) through (5,15) red. (Red is 0,1,0.5,1 in HSLA).
     * Then if the second step is right, color pixels (5,15) through (15,15) red.
     * Then if the third step is up, color pixels (15,15) through (15,5) red.
     * Continue in this manner until you get to the end of the solution vector,
     * so that your output looks analogous the above picture.
     *
     * @note: Make the exit by undoing the bottom wall of the destination square:
     * call the destination maze coordinates (x,y), and whiten the pixels with
     * coordinates (x*10+k, (y+1)*10) for k from 1 to 9.
     */
    PNG * drawMazeWithSolution();

    PNG * drawCreativeMaze();

private:
    DisjointSets set_;

    int width_;
    int height_;
    int destination_;

    // {right, down} pair
    vector<pair<bool, bool>> rd_wall_;

    /**
     * Helper function for solveMaze.
     * Adds the adjacent nodes of the current node.
     */
     void addAdjacent(vector<int> & v, int idx, int x, int y);

    /**
     * Helper function for solveMaze.
     * Search the longest distance from the origin.
     */
    int getMaxDistFromOrig(vector<int> v);

    /**
     * Helper function for drawMaze.
     * Color the pixel black.
     */
    void paintBlack(HSLAPixel * p) const;

    /**
     * Helper function for drawMazeWithSolution.
     * Color the pixel red.
     */
    void paintRed(HSLAPixel * p);

    /**
     * Helper function for drawMazeWithSolution.
     * Color the pixel white.
     */
    void paintWhite(HSLAPixel * p);
    void paintGreen(HSLAPixel * p);
    void paintBlue(HSLAPixel * p);
    void paintOrange(HSLAPixel * p);
};

#endif
