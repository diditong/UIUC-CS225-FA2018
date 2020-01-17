/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"

using namespace std;

Point<3> convertToLAB(HSLAPixel pixel) {
    Point<3> result(pixel.h/360, pixel.s, pixel.l);
    return result;
}

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage>& theTiles)
{
    /**
     * @todo Implement this function!
     */
     MosaicCanvas * myMC = new MosaicCanvas(theSource.getRows(), theSource.getColumns());
     map<Point<3>, int> pointMap;
     vector<Point<3>> pointVec;

     for (size_t i = 0; i < theTiles.size(); i++)
     {
       HSLAPixel pixel = theTiles[i].getAverageColor();
       Point<3> p(pixel.h/360.0, pixel.s, pixel.l);
       pointVec.push_back(p);
       pointMap.insert(pair<Point<3>, int> (p,i) );
     }

    KDTree<3> kd_tree(pointVec);
    int row = theSource.getRows();
    int column = theSource.getColumns();
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < column; j++)
      {
        TileImage * tile = get_match_at_idx(kd_tree,pointMap, theTiles, theSource, i, j);
        myMC->setTile(i,j,tile);
      }
    }
    return myMC;
}

TileImage* get_match_at_idx(const KDTree<3>& tree,
                                  map<Point<3>, int> tile_avg_map,
                                  vector<TileImage>& theTiles,
                                  const SourceImage& theSource, int row,
                                  int col)
{
    // Create a tile which accurately represents the source region we'll be
    // using
    HSLAPixel avg = theSource.getRegionColor(row, col);
    Point<3> avgPoint = convertToLAB(avg);
    Point<3> nearestPoint = tree.findNearestNeighbor(avgPoint);

    // Check to ensure the point exists in the map
    map< Point<3>, int >::iterator it = tile_avg_map.find(nearestPoint);
    if (it == tile_avg_map.end())
        cerr << "Didn't find " << avgPoint << " / " << nearestPoint << endl;

    // Find the index
    int index = tile_avg_map[nearestPoint];
    return &theTiles[index];

}
