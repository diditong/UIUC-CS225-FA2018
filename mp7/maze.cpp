/**
 * @file maze.h
 * @author Soohyuck Cho, Feiyang Li
 */
#include "maze.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include "dsets.h"
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
using namespace cs225;

/**
 * No-parameter constructor.
 * Creates an empty maze.
 */
SquareMaze::SquareMaze() {
    // construct a set with n nodes
    // when removing a wall, union node a and b
    // if they are in a same set, then do not remove the wall, or it will create a cycle
    // repeat until all the nodes are in one set
}

/**
 * Makes a new SquareMaze of the given height and width.
 * @param width: The width of the SquareMaze(number of cells).
 * @param height: The height of the SquareMaze(number of cells).
 */
void SquareMaze::makeMaze(int width, int height) {
    // clear previous maze info
    rd_wall_.clear();

    // initialize variables
    width_ = width; height_ = height;

    int numNodes = width_ * height_;
    set_.addelements(numNodes);

    for (int i = 0; i < numNodes; i++)
        rd_wall_.push_back({true, true});

    // remove walls
    int numEdges = 0;
    int row, col, prob, curIdx;
    while (numEdges < numNodes - 1) {
        col = rand() % width_;
        row = rand() % height_;
        curIdx = row * width_ + col;

        prob = rand() % 2;

        if (prob) {
            if (col != width_ - 1 && (set_.find(curIdx) != set_.find(curIdx + 1))) {
                rd_wall_[curIdx].first = false;
                set_.setunion(curIdx, curIdx + 1);
                numEdges++;
            }
        } else {
            if (row != height_ - 1 && (set_.find(curIdx) != set_.find(curIdx + width_))) {
                rd_wall_[curIdx].second = false;
                set_.setunion(curIdx, curIdx + width_);
                numEdges++;
            }
        }
    }
}

/**
 * Determine whether it is possible to travel in the given direction from the
 * coordinate (x, y).
 * @param x: The x coordinate of the current cell.
 * @param y: The y coordinate of the current cell.
 * @param dir: The desired direction to move from the current cell.
 * @return True if you can travel in the specified direction, false otherwise.
 */
bool SquareMaze::canTravel(int x, int y, int dir) const {
    // boundary cases
    if (x < 0 || y < 0 || x >= width_ || y >= height_
        || (dir == 0 && x == width_ - 1) || (dir == 1 && y == height_ - 1)
        || (dir == 2 && x == 0) || (dir == 3 && y == 0))
        return false;

    // determine if the given direction is traversible
    int curIdx = y * width_ + x;
    bool canMove = false;
    switch (dir) {
    case 0:
        if (!rd_wall_[curIdx].first) canMove = true;
        break;
    case 1:
        if (!rd_wall_[curIdx].second) canMove = true;
        break;
    case 2:
        if (!rd_wall_[curIdx - 1].first) canMove = true;
        break;
    case 3:
        if (!rd_wall_[curIdx - width_].second) canMove = true;
        break;
    }
    return canMove;
}

/**
 * Sets whether or not the specified wall exists.
 * @param x: The x coordinate of the current cell.
 * @param y: The y coordinate of the current cell.
 * @param dir: Either 0(right) or 1(down).
 * @param exists: True if setting the wall to exist, false otherwise.
 */
void SquareMaze::setWall(int x, int y, int dir, bool exists) {
    int curIdx = y * width_ + x;
    if (!dir)
        rd_wall_[curIdx].first = exists;
    else
        rd_wall_[curIdx].second = exists;
}

/**
 * Solves this SquareMaze.
 * @return True if you can travel in the specified direction, false otherwise.
 */
vector<int> SquareMaze::solveMaze() {
    // a vector to hold the distances from the origin (0, 0)
    vector<int> distFromOrig(width_ * height_, -1);
    // a vector to hold the previous square
    vector<int> previous(width_ * height_, -1);
    // main BFS traversal queue
    queue<int> q;

    distFromOrig[0] = 0;
    q.push(0);
    int curIdx, x, y;
    while (!q.empty()) {
        curIdx = q.front();
        x = curIdx % width_;
        y = curIdx / width_;

        // adjacenty vector that hold the neighboring squares
        vector<int> adj;
        addAdjacent(adj, curIdx, x, y);
        for (int idx : adj) {
            if (distFromOrig[idx] == -1) {
                previous[idx] = curIdx;
                distFromOrig[idx] = distFromOrig[curIdx] + 1;
                q.push(idx);
            }
        }
        q.pop();
    }

    // find the max distance and set that square as destination
    int maxDist = getMaxDistFromOrig(distFromOrig);

    // construct the solution
    vector<int> solution;
    int curCell = destination_;
    int preCell = previous[curCell];

    while (preCell != -1) {
        if (preCell + 1 == curCell)
            solution.push_back(0);
        else if(preCell + width_ == curCell)
            solution.push_back(1);
        else if(preCell - 1 == curCell)
            solution.push_back(2);
        else if(preCell - width_ == curCell)
            solution.push_back(3);
        curCell = preCell;
        preCell = previous[curCell];
    }

    reverse(solution.begin(), solution.end());
    return solution;
}

/**
 * Helper function for solveMaze.
 * Adds the adjacent nodes of the current node.
 */
 void SquareMaze::addAdjacent(vector<int> & v, int idx, int x, int y) {
     if (canTravel(x, y, 0)) v.push_back(idx + 1);
     if (canTravel(x, y, 1)) v.push_back(idx + width_);
     if (canTravel(x, y, 2)) v.push_back(idx - 1);
     if (canTravel(x, y, 3)) v.push_back(idx - width_);
 }

/**
 * Helper function for solveMaze.
 * Search the longest distance from the origin.
 */
int SquareMaze::getMaxDistFromOrig(vector<int> v) {
    int maxDist = 0;
    for (int i = width_ * (height_ - 1); i < width_ * height_; i++) {
        if (v[i] > maxDist) {
            maxDist = v[i];
            destination_ = i;
        }
    }
    return maxDist;
}

/**
 * Draws the maze without the solution.
 * @return A PNG of the unsolved SquareMaze.
 */
PNG * SquareMaze::drawMaze() const {
    // create an empty png
    int pngWidth = width_ * 10 + 1;
    int pngHeight = height_ * 10 + 1;
    PNG * maze = new PNG(pngWidth, pngHeight);
    for (int x = 10; x < pngWidth; x++)
        paintBlack(&maze->getPixel(x, 0));
    for (int y = 0; y < pngHeight; y++)
        paintBlack(&maze->getPixel(0, y));

    // color walls
    int numCells = width_ * height_;
    for (int idx = 0; idx < numCells; idx++) {
        int x = idx % width_;
        int y = idx / width_;
        if (rd_wall_[idx].first)
            for (int k = 0; k <= 10; k++)
                paintBlack(&maze->getPixel(10 * (x + 1), 10 * y + k));
        if (rd_wall_[idx].second)
            for (int k = 0; k <= 10; k++)
                paintBlack(&maze->getPixel(10 * x + k, 10 * (y + 1)));
    }
    return maze;
}

/**
 * Helper function for drawMaze.
 * Color the pixel black.
 */
void SquareMaze::paintBlack(HSLAPixel * p) const {
    // Black(0, 0, 0)
    p->h = 0;
    p->s = 0;
    p->l = 0;
}

/**
 * This function calls drawMaze, then solveMaze; it modifies the PNG from
 * drawMaze to show the solution vector and the exit.
 * @return A PNG of the solved SquareMaze.
 */
PNG * SquareMaze::drawMazeWithSolution() {
    // draw the maze
    PNG * maze = drawMaze();
    // get the solution
    vector<int> sol = solveMaze();
    // color the starting point
    int x = 5, y = 5;
    paintRed(&maze->getPixel(x, y));

    // color the solution path
    for (int dir : sol) {
        switch (dir) {
        case 0:
            for (int i = 0; i <= 10; i++)
                paintRed(&maze->getPixel(x + i, y));
            x += 10;
            break;
        case 1:
            for (int i = 0; i <= 10; i++)
                paintRed(&maze->getPixel(x, y + i));
            y += 10;
            break;
        case 2:
            for (int i = 0; i <= 10; i++)
                paintRed(&maze->getPixel(x - i, y));
            x -= 10;
            break;
        case 3:
            for (int i = 0; i <= 10; i++)
                paintRed(&maze->getPixel(x, y - i));
            y -= 10;
            break;
        }
    }

    // remove bottom wall of the destination
    int exitX = destination_ % width_;
    int exitY = destination_ / width_;
    for (int k = 1; k < 10; k++)
        paintWhite(&maze->getPixel(10 * exitX + k, 10 * (exitY + 1)));

    return maze;
}


PNG * SquareMaze::drawCreativeMaze() {
  // create an empty png
  int pngWidth = width_ * 10 + 1;
  int pngHeight = height_ * 10 + 1;
  PNG * maze = new PNG(pngWidth, pngHeight);

  // color walls
  int numCells = width_ * height_;
  for (int idx = 0; idx < numCells; idx++) {
    if (numCells*3/4 && (idx % width_) < width_/2)
    {
      int x = (idx % width_);
      int y = idx / width_;
      if (rd_wall_[idx].first)
          for (int k = 0; k <= 10; k++)
              paintOrange(&maze->getPixel(10 * (x + 1), 10 * y + k));
      if (rd_wall_[idx].second)
          for (int k = 0; k <= 10; k++)
              paintBlue(&maze->getPixel(10 * x + k, 10 * (y + 1)));
    }
  }
  for (int idx = numCells*3/4 +1; idx < numCells; idx++) {
      int x = (idx % width_);
      int y = idx / width_;
      if (rd_wall_[idx].first)
          for (int k = 0; k <= 10; k++)
              paintOrange(&maze->getPixel(10 * (x + 1), 10 * y + k));
      if (rd_wall_[idx].second)
          for (int k = 0; k <= 10; k++)
              paintBlue(&maze->getPixel(10 * x + k, 10 * (y + 1)));
  }
  // close the  maze
  for (int x = 10; x < pngWidth/2; x++)
      paintGreen(&maze->getPixel(x, 0));
  for (int y = 0; y < pngHeight; y++)
      paintGreen(&maze->getPixel(0, y));
  for (int x = pngWidth/2 +1; x < pngWidth; x++)
      paintGreen(&maze->getPixel(x, pngHeight*3/4));
  for (int y = 0; y < pngHeight*3/4+1; y++)
      paintGreen(&maze->getPixel(pngWidth/2, y));

  return maze;
}

void SquareMaze::paintGreen(HSLAPixel * p){
  // Green(130, 1, 0.5, 1)
  p->h = 130;
  p->s = 1;
  p->l = 0.5;
  p->a = 1;
}
void SquareMaze::paintBlue(HSLAPixel * p){
  // Blue(216, 1, 0.5, 1)
  p->h = 216;
  p->s = 1;
  p->l = 0.5;
  p->a = 1;
}
void SquareMaze::paintOrange(HSLAPixel * p){
  // Orange(11, 1, 0.5, 1)
  p->h = 11;
  p->s = 1;
  p->l = 0.5;
  p->a = 1;
}

/**
 * Helper function for drawMazeWithSolution.
 * Color the pixel red.
 */
void SquareMaze::paintRed(HSLAPixel * p) {
    // Red(0, 1, 0.5, 1)
    p->h = 0;
    p->s = 1;
    p->l = 0.5;
    p->a = 1;
}

/**
 * Helper function for drawMazeWithSolution.
 * Color the pixel white.
 */
void SquareMaze::paintWhite(HSLAPixel * p) {
    // White(0, 0, 1, 1)
    p->h = 0;
    p->s = 0;
    p->l = 1;
    p->a = 1;
}
