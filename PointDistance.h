#include <math.h>
#include <vector>

using namespace std;

static class PointDistance
{
public:
	static vector<pair<float,float>> GetDistancePoints(pair<float,float> pRobotLoc, pair<float,float> pObstacleLoc, float fDist);
};
