/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkImageCanvasSource2D.h,v $

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkImageCanvasSource2D - Paints on a canvas
// .SECTION Description
// vtkImageCanvasSource2D is a source that starts as a blank image.
// you may add to the image with two-dimensional drawing routines.
// It can paint multi-spectral images.  


#ifndef __vtkImageCanvasSource2D_h
#define __vtkImageCanvasSource2D_h

#include "vtkImageAlgorithm.h"

class VTK_IMAGING_EXPORT vtkImageCanvasSource2D : public vtkImageAlgorithm
{
public:
  // Description:
  // Construct an instance of vtkImageCanvasSource2D with no data.
  static vtkImageCanvasSource2D *New();

  vtkTypeRevisionMacro(vtkImageCanvasSource2D,vtkImageAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Set/Get DrawValue.  This is the value that is used when filling data
  // or drawing lines.
  vtkSetVector4Macro(DrawColor, double);
  vtkGetVector4Macro(DrawColor, double);
  void SetDrawColor(double a) {this->SetDrawColor(a, 0.0, 0.0, 0.0);}
  void SetDrawColor(double a,double b) {this->SetDrawColor(a, b, 0.0, 0.0);}
  void SetDrawColor(double a, double b, double c) {
    this->SetDrawColor(a, b, c, 0.0);}
    
  void FillBox(int min0, int max0, int min1, int max1);
  void FillTube(int x0, int y0, int x1, int y1, double radius);
  void FillTriangle(int x0, int y0, int x1, int y1, int x2, int y2);
  void DrawCircle(int c0, int c1, double radius);
  void DrawPoint(int p0, int p1);
  void DrawSegment(int x0, int y0, int x1, int y1);
  void DrawSegment3D(double *p0, double *p1);
  void DrawSegment3D(double x1, double y1, double z1, 
                     double x2, double y2, double z2) 
    { double p1[3], p2[3]; 
    p1[0] = x1; p1[1] = y1; p1[2] = z1; p2[0] = x2; p2[1] = y2; p2[2] = z2;
    this->DrawSegment3D(p1, p2);}

  // Description:
  // Draw subimage of the input image in the canvas at position x0 and
  // y0. The subimage is defined with sx, sy, width, and height.
  void DrawImage(int x0, int y0, vtkImageData* i)
    { this->DrawImage(x0, y0, i, -1, -1, -1, -1); }
  void DrawImage(int x0, int y0, vtkImageData*, int sx, int sy,
                 int width, int height);

  // Description:
  // Fill a colored area with another color. (like connectivity)
  // All pixels connected (and with the same value) to pixel (x, y) 
  // get replaced by the current "DrawColor".
  void FillPixel(int x, int y);

  // Description:
  // These methods set the WholeExtent of the output
  // It sets the size of the canvas.
  // Extent is a min max 3D box.  Minimums and maximums are inclusive.
  void SetExtent(int *extent);
  void SetExtent(int x1, int x2, int y1, int y2, int z1, int z2);
  
  // Description:
  // The drawing operations can only draw into one 2D XY plane at a time.
  // If the canvas is a 3D volume, then this z value is used
  // as the default for 2D operations.
  vtkSetMacro(DefaultZ, int);
  vtkGetMacro(DefaultZ, int);

  // Description:
  // Set/Get Ratio. This is the value that is used to pre-multiply each
  // (x, y, z) drawing coordinates (including DefaultZ).
  vtkSetVector3Macro(Ratio, double);
  vtkGetVector3Macro(Ratio, double);

  // Description:
  // Set the number of scalar components
  virtual void SetNumberOfScalarComponents(int i);
  
  // Description:
  // Set/Get the data scalar type (i.e VTK_DOUBLE). Note that these methods
  // are setting and getting the pipeline scalar type. i.e. they are setting
  // the type that the image data will be once it has executed. Until the
  // REQUEST_DATA pass the actual scalars may be of some other type. This is
  // for backwards compatibility
  void SetScalarTypeToFloat(){this->SetScalarType(VTK_FLOAT);};
  void SetScalarTypeToDouble(){this->SetScalarType(VTK_DOUBLE);};
  void SetScalarTypeToInt(){this->SetScalarType(VTK_INT);};
  void SetScalarTypeToUnsignedInt()
    {this->SetScalarType(VTK_UNSIGNED_INT);};
  void SetScalarTypeToLong(){this->SetScalarType(VTK_LONG);};
  void SetScalarTypeToUnsignedLong()
    {this->SetScalarType(VTK_UNSIGNED_LONG);};
  void SetScalarTypeToShort(){this->SetScalarType(VTK_SHORT);};
  void SetScalarTypeToUnsignedShort()   
    {this->SetScalarType(VTK_UNSIGNED_SHORT);};
  void SetScalarTypeToUnsignedChar()
    {this->SetScalarType(VTK_UNSIGNED_CHAR);};
  void SetScalarTypeToChar()
    {this->SetScalarType(VTK_CHAR);};
  void SetScalarType(int);  
  
protected:
  vtkImageCanvasSource2D();
  // Destructor: Deleting a vtkImageCanvasSource2D automatically deletes the
  // associated vtkImageData.  However, since the data is reference counted,
  // it may not actually be deleted.
  ~vtkImageCanvasSource2D();

  vtkImageData *ImageData;
  int WholeExtent[6];
  double DrawColor[4];
  int DefaultZ;
  double Ratio[3];
  
  int ClipSegment(int &a0, int &a1, int &b0, int &b1);
  
  virtual int RequestInformation (vtkInformation *, 
                                  vtkInformationVector**, 
                                  vtkInformationVector *);
  virtual int RequestData (vtkInformation *, 
                           vtkInformationVector**, 
                           vtkInformationVector *);

private:
  vtkImageCanvasSource2D(const vtkImageCanvasSource2D&);  // Not implemented.
  void operator=(const vtkImageCanvasSource2D&);  // Not implemented.
};



#endif


