#include "CameraBase.h"

using namespace MathLib;


#ifdef MEMORY_INFO
#define new new(__FILE__, __LINE__) 
#endif // MEMORY_INFO




CCameraBase::CCameraBase(): CPlayer(PLAYER_SPECTATOR) 
{

}

CCameraBase::~CCameraBase()
{
    Leave();
}