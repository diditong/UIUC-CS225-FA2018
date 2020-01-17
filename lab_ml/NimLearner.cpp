/**
 * @file NimLearner.cpp
 * CS 225: Data Structures
 */

#include "NimLearner.h"
#include <ctime>

using namespace std;
/**
 * Constructor to create a game of Nim with `startingTokens` starting tokens.
 *
 * This function creates a graph, `g_` representing all of the states of a
 * game of Nim with vertex labels "p#-X", where:
 * - # is the current player's turn; p1 for Player 1, p2 for Player2
 * - X is the tokens remaining at the start of a player's turn
 *
 * For example:
 *   "p1-4" is Player 1's turn with four (4) tokens remaining
 *   "p2-8" is Player 2's turn with eight (8) tokens remaining
 *
 * All legal moves between states are created as edges with initial weights
 * of 0.
 *
 * @param startingTokens The number of starting tokens in the game of Nim.
 */
NimLearner::NimLearner(unsigned startingTokens) : g_(true, true)
{
    /* Your code goes here! */
    g_ = new Graph(true, true);

    for (unsigned i = 0; i < startingTokens+1; i++) // startingTokens+1 because of the state of 0 tokens
    {
      g_.insertVertexByLabel("p1-" + to_string(i));
      g_.insertVertexByLabel("p2-" + to_string(i));
    }
    startingVertex_ = g_.getVertexByLabel("p1-" + to_string(startingTokens));

    for (unsigned i = startingTokens; i > 1; i--)
    {
      Vertex start = g_.getVertexByLabel("p1-" + to_string(i));
      Vertex dest1 = g_.getVertexByLabel("p2-" + to_string(i-1));
      Vertex dest2 = g_.getVertexByLabel("p2-" + to_string(i-2));

      g_.insertEdge(start, dest1);
      g_.setEdgeWeight(start, dest1, 0);
      g_.insertEdge(start, dest2);
      g_.setEdgeWeight(start, dest2, 0);
    }
    Vertex start = g_.getVertexByLabel("p1-" + to_string(1));
    Vertex dest1 = g_.getVertexByLabel("p2-" + to_string(0));
    g_.insertEdge(start, dest1);
    g_.setEdgeWeight(start, dest1, 0);

    for (unsigned i = startingTokens; i > 1; i--)
    {
      Vertex start = g_.getVertexByLabel("p2-" + to_string(i));
      Vertex dest1 = g_.getVertexByLabel("p1-" + to_string(i-1));
      Vertex dest2 = g_.getVertexByLabel("p1-" + to_string(i-2));

      g_.insertEdge(start, dest1);
      g_.setEdgeWeight(start, dest1, 0);
      g_.insertEdge(start, dest2);
      g_.setEdgeWeight(start, dest2, 0);
    }
    start = g_.getVertexByLabel("p2-" + to_string(1));
    dest1 = g_.getVertexByLabel("p1-" + to_string(0));
    g_.insertEdge(start, dest1);
    g_.setEdgeWeight(start, dest1, 0);
}

/**
 * Plays a random game of Nim, returning the path through the state graph
 * as a vector of `Edge` classes.  The `origin` of the first `Edge` must be
 * the vertex with the label "p1-#", where # is the number of starting
 * tokens.  (For example, in a 10 token game, result[0].origin must be the
 * vertex "p1-10".)
 *
 * @returns A random path through the state space graph.
 */
std::vector<Edge> NimLearner::playRandomGame() const {
  vector<Edge> path;

 Vertex start = startingVertex_;
 int next = 0;
 int temp = rand()%2;
 if (0<((stoi(g_.getVertexLabel(start).substr(3))) -1 -temp) )
 {
   next = stoi(g_.getVertexLabel(start).substr(3)) -1 -temp;
 }
 Vertex end = g_.getVertexByLabel("p2-" + to_string(next));
 path.push_back(g_.getEdge(start, end));

 while(g_.getVertexLabel(end).substr(3) != "0")
 {
   start = end;
   temp = rand()%2;
   if (0<(stoi(g_.getVertexLabel(start).substr(3)) -1 -temp))
     next = stoi(g_.getVertexLabel(start).substr(3)) -1 -temp;
   else
     next = 0;

  if (g_.getVertexLabel(start).substr(1,1) == "1")
    end = "p2-" + to_string(next);
  else
    end = "p1-" + to_string(next);
  path.push_back(g_.getEdge(start, end));
 }
  return path;
}

/*
 * Updates the edge weights on the graph based on a path through the state
 * tree.
 *
 * If the `path` has Player 1 winning (eg: the last vertex in the path goes
 * to Player 2 with no tokens remaining, or "p2-0", meaning that Player 1
 * took the last token), then all choices made by Player 1 (edges where
 * Player 1 is the source vertex) are rewarded by increasing the edge weight
 * by 1 and all choices made by Player 2 are punished by changing the edge
 * weight by -1.
 *
 * Likewise, if the `path` has Player 2 winning, Player 2 choices are
 * rewarded and Player 1 choices are punished.
 *
 * @param path A path through the a game of Nim to learn.
 */
void NimLearner::updateEdgeWeights(const std::vector<Edge> & path)
{
  if (g_.getVertexLabel(path[path.size()-1].dest).substr(1,1) == "1")
  {// Player 2 win
    for (auto &it :  path)
    {
      if (g_.getVertexLabel(it.dest).substr(1,1)=="1")
        g_.setEdgeWeight(it.source, it.dest, g_.getEdgeWeight(it.source, it.dest)+1);
      else
        g_.setEdgeWeight(it.source, it.dest, g_.getEdgeWeight(it.source, it.dest)-1);
    }
  }
  else
  {// Player 1 win
    for (auto &it :  path)
    {
      if (g_.getVertexLabel(it.dest).substr(1,1)=="2")
        g_.setEdgeWeight(it.source, it.dest, g_.getEdgeWeight(it.source, it.dest)+1);
      else
        g_.setEdgeWeight(it.source, it.dest, g_.getEdgeWeight(it.source, it.dest)-1);
    }
  }

}

/**
 * Label the edges as "WIN" or "LOSE" based on a threshold.
 */
void NimLearner::labelEdgesFromThreshold(int threshold) {
  for (const Vertex & v : g_.getVertices()) {
    for (const Vertex & w : g_.getAdjacent(v)) {
      int weight = g_.getEdgeWeight(v, w);

      // Label all edges with positve weights as "WINPATH"
      if (weight > threshold)           { g_.setEdgeLabel(v, w, "WIN"); }
      else if (weight < -1 * threshold) { g_.setEdgeLabel(v, w, "LOSE"); }
    }
  }
}

/**
 * Returns a constant reference to the state space graph.
 *
 * @returns A constant reference to the state space graph.
 */
const Graph & NimLearner::getGraph() const {
  return g_;
}
