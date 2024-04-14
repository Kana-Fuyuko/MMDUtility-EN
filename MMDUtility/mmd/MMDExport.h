///////////////////////////////////////////////////////////////////////////
// MMDExport.h Ver.0.07 2010/10/22 MikuMikuDance Header for export function
//
// Library of output functions：MMDExport.lib
///////////////////////////////////////////////////////////////////////////
#ifndef __MMDEXPORT_H__								// Duplication prevention
#define __MMDEXPORT_H__

///////////////// _EXPORT Definition //////////////////
//#define		_EXPORT	__declspec(dllexport)			// For MMD itself (comment out on the dll side)
#define	_EXPORT	__declspec(dllimport)			// For DLL		(Uncomment it on the dll side)
#pragma comment(lib,"mmd/mmdexport")

///////////// Export Function ////////////////
extern "C" {
  _EXPORT	float			ExpGetFrameTime();				// Obtain frame time (sec) Time currently being processed with frame 0 as 0sec
  _EXPORT	int				ExpGetPmdNum();					// Number of PMD models
  _EXPORT	char*			ExpGetPmdFilename(int);			// PMD model file name of argument 1 (full path) Argument 1 is 0 to GetPmdNum-1
  _EXPORT	int				ExpGetPmdOrder(int);			// PMD model drawing order of argument 1 (*1) Argument 1 is 0 to GetPmdNum-1
  _EXPORT	int				ExpGetPmdMatNum(int);			// Number of materials in the PMD model with argument 1 Argument 1 is 0 to GetPmdNum-1
  _EXPORT	D3DMATERIAL9	ExpGetPmdMaterial(int, int);		// Material of PMD model of argument 1 Argument 1 is 0 to GetPmdNum-1, argument 2 is 0 to GetPmdMatNum(argument 1)-1
  _EXPORT	int				ExpGetPmdBoneNum(int);			// Number of bones in the PMD model with argument 1 Argument 1 is 0 to GetPmdNum-1
  _EXPORT	char*			ExpGetPmdBoneName(int, int);		// Bone name of PMD model of argument 1 Argument 1 is 0 to GetPmdNum-1, argument 2 is 0 to GetPmdBoneNum(argument 1)-1
  _EXPORT	D3DMATRIX		ExpGetPmdBoneWorldMat(int, int);	// World matrix of bones of PMD model with argument 1 (*2) Argument 1 is 0 to GetPmdNum-1, argument 2 is 0 to GetPmdBoneNum(argument 1)-1
  _EXPORT	int				ExpGetPmdMorphNum(int);			// Number of facial expressions in the PMD model with argument 1 Argument 1 is 0 to GetPmdNum-1
  _EXPORT	char*			ExpGetPmdMorphName(int, int);	// Facial expression name of PMD model of argument 1 Argument 1 is 0 to GetPmdNum-1, argument 2 is 0 to GetPmdMorphNum(argument 1)-1
  _EXPORT	float			ExpGetPmdMorphValue(int, int);	// Expression value of PMD model of argument 1 Argument 1 is 0 to GetPmdNum-1, argument 2 is 0 to GetPmdMorphNum(argument 1)-1
  _EXPORT	bool			ExpGetPmdDisp(int);				// Display status of PMD model of argument 1 (true: display) Argument 1 is 0 to GetPmdNum-1
  _EXPORT	int				ExpGetPmdID(int);				// PMD model ID of argument 1 Argument 1 is 0 to GetPmdNum-1

  _EXPORT	int				ExpGetAcsNum();					// number of accessories
  _EXPORT	int				ExpGetPreAcsNum();				// Number of accessories depicted before model
  _EXPORT	char*			ExpGetAcsFilename(int);			// Number 1 access file name (full path) Argument 1 is 0 to GetAcsNum-1
  _EXPORT	int				ExpGetAcsOrder(int);			// Access drawing order of argument 1 (*1) Argument 1 is 0 to GetAcsNum-1
  _EXPORT	D3DMATRIX		ExpGetAcsWorldMat(int);			// World matrix of accesses for argument 1 (*2) Argument 1 is 0 to GetAcsNum-1
  _EXPORT	float			ExpGetAcsX(int);				// Argument 1 access position X (access panel X) Argument 1 is 0 to GetAcsNum-1
  _EXPORT	float			ExpGetAcsY(int);				// Argument 1 access position Y (access panel Y) Argument 1 is 0 to GetAcsNum-1
  _EXPORT	float			ExpGetAcsZ(int);				// Argument 1 access position Z (access panel Z) Argument 1 is 0 to GetAcsNum-1
  _EXPORT	float			ExpGetAcsRx(int);				// Argument 1 Accessory rotation X (Access panel Rx) Argument 1 is 0 to GetAcsNum-1
  _EXPORT	float			ExpGetAcsRy(int);				// Rotation Y of the accessory of argument 1 (Ry of the accessory panel) Argument 1 is 0 to GetAcsNum-1
  _EXPORT	float			ExpGetAcsRz(int);				// Rotation Z of the accessory with argument 1 (Rz of the accessory panel) Argument 1 is 0 to GetAcsNum-1
  _EXPORT	float			ExpGetAcsSi(int);				// Argument 1 access size (access panel Si) Argument 1 is 0 to GetAcsNum-1
  _EXPORT	float			ExpGetAcsTr(int);				// Access transparency of argument 1 (Access panel Tr) Argument 1 is 0 to GetAcsNum-1
  _EXPORT	bool			ExpGetAcsDisp(int);				// Access display status of argument 1 (true: display) Argument 1 is 0 to GetAcsNum-1
  _EXPORT	int				ExpGetAcsID(int);				// Access ID of argument 1 Argument 1 is 0 to GetAcsNum-1
  _EXPORT	int				ExpGetAcsMatNum(int);			// Access material number of argument 1 Argument 1 is 0 to GetAcsNum-1
  _EXPORT	D3DMATERIAL9	ExpGetAcsMaterial(int, int);		// Accessory material of argument 1 Argument 1 is 0 to GetAcsNum-1, argument 2 is 0 to GetAcsMatNum(argument 1)-1

  _EXPORT	int				ExpGetCurrentObject();			// Object currently being processed (*1)
  _EXPORT	int				ExpGetCurrentMaterial();		// Materials currently being processed (*3)
  _EXPORT	int				ExpGetCurrentTechnic();			// Technique currently being processed (0: Other 1: Normal drawing (self-shadow OFF) 2: Normal drawing (self-shadow ON)
                              // 3: Shadow (non-self-shadow) 4: Edge 5: Z-buffer plot for self-shadow
  _EXPORT	void			ExpSetRenderRepeatCount(int);	// Repeat the rendering process the number of times argument 1 (*4)
  _EXPORT	int				ExpGetRenderRepeatCount();		// Number of rendering processing repetitions (*4)
  _EXPORT	bool			ExpGetEnglishMode();			// English mode or not (true: English mode false: Japanese mode)
}

#endif	// __MMDEXPORT_H__


/*
*1 Regarding drawing order

In MMD,

A. Accessory depiction drawn before the model
B. Model depiction
C. Accessory depiction drawn after the model

are depicted in this order.

The ExpGetPmdOrder, ExpGetAcsOrder, and ExpGetCurrentObject functions return numbers in ABC order, but only the value of A is returned as a negative value.

Example) When drawn in the following order: stage.x negi.x Hatsune Miku.pmd Kagamine Rin.pmd Light B.x Light R.x
   Return value of ExpGetPmdOrder, ExpGetAcsOrder, ExpGetCurrentObject functions

stage.x -1
negi.x -2
hatsune miku.pmd 3
Kagamine Rin.pmd 4
Light B.x 5
Light R.x 6

ExpGetCurrentObject returns 0 except when drawing models and accessories.
ExpGetCurrentObject returns the above value when drawing models and accessories, and when using the Z buffer for shadows, edges, and self-shadows.


*2 About the world matrix
The MMD camera is designed to only move distance in 3D space, and objects can move and rotate.
In other words, the world transformation matrix of each object changes depending on the position and rotation of the camera.
The world matrix of the export function now outputs the value before it is multiplied by the camera position and rotation factors.
Therefore, the value is different from the world matrix obtained by D3DDevice->GetTransform(D3DTS_WORLD,&world).
Please note that if you use this value as the world matrix for vertex calculation in fx, it will not be displayed in the correct position.

ExpGetPmdBoneWorldMat: If the accessory is model-following, it will be the value already multiplied by the model's world matrix.


*3 About the return value of ExpGetCurrentMaterial
A value is also returned when processing the Z buffer for shadows, edges, and self-shadows.
However, in the above case, all materials are actually ignored and rendered with a single material, but
The return value of ExpGetCurrentMaterial returns the material number when drawing normally.


*4 About ExpSetRenderRepeatCount
ExpSetRenderRepeatCount sets the value of the MMD internal variable ExRepeat.
ExpGetRenderRepeatCount gets the value of ExRepeat.
The rough sequence of one frame is as follows.

{
   ***World matrix settings***
   ***Clear surface/Z buffer***

   ExRepeat=1;
     if( SUCCEEDED( Dx3d->lpDevice->BeginScene() ) )
     {
     ***Z-buffer depiction for self-shadow***

     while(ExRepeat>0){
       ExRepeat--;
       ***Rendering processing related to models and accessories***
     }

     ***Screen capture processing (for screen processing)***
     ***Text, bone line, physical rigid body (when displayed) and various sprite display processing (omitted when outputting AVI)***

     Dx3d->lpDevice->EndScene();
   }

   ***AVI output processing (when outputting AVI)***
   ***Bone calculation for next frame***
   ***Physical calculation***
   ***Moving model vertices***
   ***Key input processing, etc.***

   Dx3d->lpDevice->Present();

   ***Recovery process when device is lost***
}

In DirectX, only a pair of BeginScene()/EndScene() can be used for one Present().
(Multiple pairs may be used if the rendering target is different for each pair), and the above configuration was used.

ExpSetRenderRepeatCount() is
・First, set the repeat count in the function that hooks BeginScene() ( ExpSetRenderRepeatCount(n) )
・By sending ExpSetRenderRepeatCount(1) as necessary during the fx rendering process, one more
  ***Rendering processing related to models and accessories***Generate a turn

You can use it as (probably).


***Rendering processing related to models and accessories*** sequence
{
   ***Sprite depiction for background BMP***
   ***Sprite depiction for background AVI***
   ***Coordinate axis depiction***
   ***Floor depiction (transparent)***
   ***Accessories set depicted before model***
   ***Ground shadow depiction***{
     Complete set of accessories // Not necessarily in the order of ExpGetAcsOrder
     complete model
   }
   ***Complete model representation***
   ***Edge set depiction***
   ***A complete set of accessories depicted after the model***
}
*/


/*
Change log
Ver.0.08 (2013/06/30)
- Added ExpGetEnglishMode function (English mode when true)

Ver.0.07 (2010/10/22)
・ExpGetCurrentMaterial()のバグ修正

Ver.0.06 (2010/10/21)
- Bug fixes for ExpGetPmdOrder() and ExpGetCurrentObject()

Ver.0.05 (2010/10/07)
- Added ExpGetRenderRepeatCount function
・Remove Z-buffer depiction for self-shadow from the rendering loop

Ver.0.04 (2010/10/06)
- Added the following functions
   ExpGetCurrentTechnic,ExpSetRenderRepeatCount
・The return values of ExpGetCurrentObject and ExpGetCurrentMaterial are used when drawing shadows and edges.
  Changed the specification so that the object number and material number being processed are returned even when plotting Z buffer for self-shadow.
・Fixed a bug where ExpGetCurrentObject and ExpGetCurrentMaterial values were not returned when self-shadow was turned off in the MMD menu.

Ver.0.03 (2010/09/29)
・Add the following functions
  ExpGetPmdBoneNum,ExpGetPmdBoneName,ExpGetPmdBoneWorldMat,ExpGetPmdMorphNum,ExpGetPmdMorphName,
  ExpGetPmdMorphValue,ExpGetPmdDisp,ExpGetPmdID,ExpGetAcsDisp,ExpGetAcsID,ExpGetAcsMatNum,
  ExpGetAcsMaterial,ExpGetCurrentMaterial
・Changed the return value of ExpGetCurrentObject to 0 except when accessing model.

Ver.0.02 (2010/09/28)
・Wrap EXPORT definition in extern "C"

*/
