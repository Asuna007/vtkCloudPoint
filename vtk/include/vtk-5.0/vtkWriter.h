/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkWriter.h,v $

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkWriter - abstract class to write data to file(s)
// .SECTION Description
// vtkWriter is an abstract class for mapper objects that write their data
// to disk (or into a communications port). All writers respond to Write()
// method. This method insures that there is input and input is up to date.
//
// Since vtkWriter is a subclass of vtkProcessObject, StartMethod(), 
// EndMethod(), and ProgressMethod() are all available to writers.
// These methods are executed before and after execution of the Write() 
// method. You can also specify arguments to these methods.

// .SECTION Caveats
// Every subclass of vtkWriter must implement a WriteData() method. Most likely
// will have to create SetInput() method as well.

// .SECTION See Also
// vtkBYUWriter vtkDataWriter vtkSTLWriter vtkVoxelWriter vtkMCubesWriter

#ifndef __vtkWriter_h
#define __vtkWriter_h

#include "vtkAlgorithm.h"

class vtkDataObject;

#define VTK_ASCII 1
#define VTK_BINARY 2

class VTK_IO_EXPORT vtkWriter : public vtkAlgorithm
{
public:
  vtkTypeRevisionMacro(vtkWriter,vtkAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent);
  
  // Description:
  // Write data to output. Method executes subclasses WriteData() method, as 
  // well as StartMethod() and EndMethod() methods.
  // Returns 1 on success and 0 on failure.
  virtual int Write();

  // Description:
  // Encode the name so that the reader will not have problems.
  // The resulting string is up to four time the size of the input 
  // string.
  void EncodeArrayName(char* resname, const char* name);
  
  // Description:
  // Set/get the input to this writer.
  void SetInput(vtkDataObject *input);
  void SetInput(int index, vtkDataObject *input);
//BTX
  vtkDataObject *GetInput();
  vtkDataObject *GetInput(int port);
//ETX

protected:
  vtkWriter();
  ~vtkWriter();

  virtual int ProcessRequest(vtkInformation *request,
                             vtkInformationVector **inputVector,
                             vtkInformationVector *outputVector);
  virtual int RequestData(vtkInformation *request,
                          vtkInformationVector **inputVector,
                          vtkInformationVector *outputVector);

  virtual void WriteData() = 0; //internal method subclasses must respond to
  vtkTimeStamp WriteTime;
private:
  vtkWriter(const vtkWriter&);  // Not implemented.
  void operator=(const vtkWriter&);  // Not implemented.
};

#endif
