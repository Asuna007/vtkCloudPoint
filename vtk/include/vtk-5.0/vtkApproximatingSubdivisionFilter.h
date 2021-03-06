/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkApproximatingSubdivisionFilter.h,v $

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkApproximatingSubdivisionFilter - generate a subdivision surface using an Approximating Scheme
// .SECTION Description
// vtkApproximatingSubdivisionFilter is an abstract class that defines
// the protocol for Approximating subdivision surface filters.

// .SECTION Thanks
// This work was supported by PHS Research Grant No. 1 P41 RR13218-01
// from the National Center for Research Resources.

#ifndef __vtkApproximatingSubdivisionFilter_h
#define __vtkApproximatingSubdivisionFilter_h

#include "vtkPolyDataAlgorithm.h"

class vtkCellArray;
class vtkCellData;
class vtkIdList;
class vtkIntArray;
class vtkPoints;
class vtkPointData;

class VTK_GRAPHICS_EXPORT vtkApproximatingSubdivisionFilter : public vtkPolyDataAlgorithm
{
public:
  vtkTypeRevisionMacro(vtkApproximatingSubdivisionFilter,vtkPolyDataAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Set/get the number of subdivisions.
  vtkSetMacro(NumberOfSubdivisions,int);
  vtkGetMacro(NumberOfSubdivisions,int);

protected:
  vtkApproximatingSubdivisionFilter();
  ~vtkApproximatingSubdivisionFilter() {};

  int RequestData(vtkInformation *, vtkInformationVector **, vtkInformationVector *);
  virtual void GenerateSubdivisionPoints (vtkPolyData *inputDS,
                                          vtkIntArray *edgeData,
                                          vtkPoints *outputPts,
                                          vtkPointData *outputPD) = 0;
  void GenerateSubdivisionCells (vtkPolyData *inputDS, vtkIntArray *edgeData,
                                 vtkCellArray *outputPolys,
                                 vtkCellData *outputCD);
  int FindEdge (vtkPolyData *mesh, vtkIdType cellId, vtkIdType p1,
                vtkIdType p2, vtkIntArray *edgeData, vtkIdList *cellIds);
  vtkIdType InterpolatePosition (vtkPoints *inputPts, vtkPoints *outputPts,
                                 vtkIdList *stencil, double *weights);
  int NumberOfSubdivisions;
private:
  vtkApproximatingSubdivisionFilter(const vtkApproximatingSubdivisionFilter&);  // Not implemented.
  void operator=(const vtkApproximatingSubdivisionFilter&);  // Not implemented.
};

#endif
