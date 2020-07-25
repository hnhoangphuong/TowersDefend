#include "cocos2d.h"
#include <vector>
using namespace std;
USING_NS_CC;
class ListPoint:public cocos2d::Node
{
private:
    vector<Vec2> mapPoint;
public:
    ~ListPoint(){};
    ListPoint(int numOfPoint)
    {
        for(int i=0;i<numOfPoint;i++)
        {
            mapPoint.push_back(cocos2d::Vec2(0,0));
        }
    };
    void setPoint(cocos2d::Vec2 pos,int name)
        {
            log("HNHP----------%f, %f", pos.x, pos.y );
            mapPoint[name].x = pos.x;
        }
    cocos2d::Vec2 getPoint(int name)
        {
            return mapPoint[name];
        }
    // Vector<Vec2> getMapPoints()
    // {
    //     return mapPoint;
    // }

};