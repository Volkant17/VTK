if(ANDROID OR APPLE_IOS) # No GL2PS on mobile
  return()
endif()

vtk_module(vtkIOExportOpenGL2
  TCL_NAME
    vtkIOExportOpenGLII
  IMPLEMENTS
    vtkIOExport
  BACKEND
    OpenGL2
  DEPENDS
    vtkCommonCore
    vtkIOExport
    vtkRenderingGL2PSOpenGL2
  PRIVATE_DEPENDS
    vtkgl2ps
  TEST_DEPENDS
    vtkRenderingContextOpenGL2
    vtkTestingRendering
    vtkViewsContext2D
)
