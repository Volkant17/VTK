/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkClearZPass.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkClearZPass - Clear the depth buffer with a given value.
// .SECTION Description
// Clear the depth buffer with a given value.
//
// .SECTION See Also
// vtkRenderPass

#ifndef vtkClearZPass_h
#define vtkClearZPass_h

#include "vtkRenderingOpenGLModule.h" // For export macro
#include "vtkRenderPass.h"

class vtkOpenGLRenderWindow;

class VTKRENDERINGOPENGL_EXPORT vtkClearZPass : public vtkRenderPass
{
public:
  static vtkClearZPass *New();
  vtkTypeMacro(vtkClearZPass,vtkRenderPass);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Perform rendering according to a render state \p s.
  // \pre s_exists: s!=0
  virtual void Render(const vtkRenderState *s);

  // Description:
  // Set/Get the depth value. Initial value is 1.0 (farest).
  vtkSetClampMacro(Depth,double,0.0,1.0);
  vtkGetMacro(Depth,double);

 protected:
  // Description:
  // Default constructor.
  vtkClearZPass();

  // Description:
  // Destructor.
  virtual ~vtkClearZPass();

  double Depth;

 private:
  vtkClearZPass(const vtkClearZPass&) VTK_DELETE_FUNCTION;
  void operator=(const vtkClearZPass&) VTK_DELETE_FUNCTION;
};

#endif
