#ifndef __NURBSPATH_H__
#define __NURBSPATH_H__

#include <list>
#include <vector>
#include "show/PathGraph.h"
//#include "../map_sim/EdgeList.h"

/**
 *  @class NurbsPath
 *  This class uses Non-Uniform rational B-Splines (NURBS) to smoothen
 *  a given path of nodes.
 *  @author Anton Fl&uuml;gge
 *  @author Hannes Schulz
 */

class NurbsPath{
  public:
    static std::vector<double> camRatio;
    NurbsPath(){}
    std::vector<PointXY> getNurbsPath(std::list<PGNode*>&, unsigned int, int);
    std::vector<PointXY> getNurbsPath(std::vector<PointXY>&, unsigned int, int);
  private:
    float coxDeBoor(float u,int i,int k,const float* Knots);
    void getOutpoint(float t,float OutPoint[],float*opx,float*opy,const float*knots);
    unsigned int ivN;
    unsigned int ivDegree;
    unsigned int ivOrder;
    unsigned int ivNumKnots;
    unsigned int ivNumP;
};

#endif /* __NURBSPATH_H__ */
