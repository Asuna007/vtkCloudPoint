# Directory containing class headers.
SET(VTK_IO_HEADER_DIR "${VTK_INSTALL_PREFIX}/include/vtk-5.0")

# Classes in vtkIO.
SET(VTK_IO_CLASSES
  "vtkAVSucdReader"
  "vtkBMPReader"
  "vtkBMPWriter"
  "vtkBYUReader"
  "vtkBYUWriter"
  "vtkBase64InputStream"
  "vtkBase64OutputStream"
  "vtkBase64Utilities"
  "vtkCGMWriter"
  "vtkChacoReader"
  "vtkDEMReader"
  "vtkDICOMImageReader"
  "vtkDataCompressor"
  "vtkDataObjectReader"
  "vtkDataObjectWriter"
  "vtkDataReader"
  "vtkDataSetReader"
  "vtkDataSetWriter"
  "vtkDataWriter"
  "vtkEnSight6BinaryReader"
  "vtkEnSight6Reader"
  "vtkEnSightGoldBinaryReader"
  "vtkEnSightGoldReader"
  "vtkEnSightMasterServerReader"
  "vtkEnSightReader"
  "vtkFacetWriter"
  "vtkGESignaReader"
  "vtkGAMBITReader"
  "vtkGaussianCubeReader"
  "vtkGenericEnSightReader"
  "vtkGenericMovieWriter"
  "vtkIVWriter"
  "vtkImageReader"
  "vtkImageReader2"
  "vtkImageReader2Collection"
  "vtkImageReader2Factory"
  "vtkImageWriter"
  "vtkInputStream"
  "vtkJPEGReader"
  "vtkJPEGWriter"
  "vtkMCubesReader"
  "vtkMCubesWriter"
  "vtkMedicalImageProperties"
  "vtkMedicalImageReader2"
  "vtkMetaImageReader"
  "vtkMetaImageWriter"
  "vtkMultiBlockPLOT3DReader"
  "vtkMoleculeReaderBase"
  "vtkOBJReader"
  "vtkOutputStream"
  "vtkPDBReader"
  "vtkPLOT3DReader"
  "vtkPLY"
  "vtkPLYReader"
  "vtkPLYWriter"
  "vtkPNGReader"
  "vtkPNGWriter"
  "vtkPNMReader"
  "vtkPNMWriter"
  "vtkParticleReader"
  "vtkPolyDataReader"
  "vtkPolyDataWriter"
  "vtkPostScriptWriter"
  "vtkRectilinearGridReader"
  "vtkRectilinearGridWriter"
  "vtkSLCReader"
  "vtkSTLReader"
  "vtkSTLWriter"
  "vtkSimplePointsReader"
  "vtkStructuredGridReader"
  "vtkStructuredGridWriter"
  "vtkStructuredPointsReader"
  "vtkStructuredPointsWriter"
  "vtkTIFFReader"
  "vtkTIFFWriter"
  "vtkUGFacetReader"
  "vtkUnstructuredGridReader"
  "vtkUnstructuredGridWriter"
  "vtkVolume16Reader"
  "vtkVolumeReader"
  "vtkWriter"
  "vtkXMLDataElement"
  "vtkXMLDataParser"
  "vtkXMLDataReader"
  "vtkXMLDataSetWriter"
  "vtkXMLFileReadTester"
  "vtkXMLImageDataReader"
  "vtkXMLImageDataWriter"
  "vtkXMLPDataReader"
  "vtkXMLPDataSetWriter"
  "vtkXMLPDataWriter"
  "vtkXMLPImageDataReader"
  "vtkXMLPImageDataWriter"
  "vtkXMLPPolyDataReader"
  "vtkXMLPPolyDataWriter"
  "vtkXMLPRectilinearGridReader"
  "vtkXMLPRectilinearGridWriter"
  "vtkXMLPStructuredDataReader"
  "vtkXMLPStructuredDataWriter"
  "vtkXMLPStructuredGridReader"
  "vtkXMLPStructuredGridWriter"
  "vtkXMLPUnstructuredDataReader"
  "vtkXMLPUnstructuredDataWriter"
  "vtkXMLPUnstructuredGridReader"
  "vtkXMLPUnstructuredGridWriter"
  "vtkXMLParser"
  "vtkXMLPolyDataReader"
  "vtkXMLPolyDataWriter"
  "vtkXMLReader"
  "vtkXMLRectilinearGridReader"
  "vtkXMLRectilinearGridWriter"
  "vtkXMLStructuredDataReader"
  "vtkXMLStructuredDataWriter"
  "vtkXMLStructuredGridReader"
  "vtkXMLStructuredGridWriter"
  "vtkXMLUnstructuredDataReader"
  "vtkXMLUnstructuredDataWriter"
  "vtkXMLUnstructuredGridReader"
  "vtkXMLUnstructuredGridWriter"
  "vtkXMLUtilities"
  "vtkXMLWriter"
  "vtkXMLWriterC"
  "vtkXYZMolReader"
  "vtkZLibDataCompressor"
  "vtkAVIWriter"
  "vtkMPEG2Writer")

# Abstract classes in vtkIO.
SET(VTK_IO_CLASSES_ABSTRACT
  "vtkDataCompressor"
  "vtkEnSightReader"
  "vtkGenericMovieWriter"
  "vtkMoleculeReaderBase"
  "vtkVolumeReader"
  "vtkWriter"
  "vtkXMLDataReader"
  "vtkXMLPDataReader"
  "vtkXMLPDataWriter"
  "vtkXMLPStructuredDataReader"
  "vtkXMLPStructuredDataWriter"
  "vtkXMLPUnstructuredDataReader"
  "vtkXMLPUnstructuredDataWriter"
  "vtkXMLReader"
  "vtkXMLStructuredDataReader"
  "vtkXMLStructuredDataWriter"
  "vtkXMLUnstructuredDataReader"
  "vtkXMLUnstructuredDataWriter"
  "vtkXMLWriter")

# Wrap-exclude classes in vtkIO.
SET(VTK_IO_CLASSES_WRAP_EXCLUDE
  "vtkPLY"
  "vtkXMLWriterC")

# Set convenient variables to test each class.
FOREACH(class ${VTK_IO_CLASSES})
  SET(VTK_CLASS_EXISTS_${class} 1)
ENDFOREACH(class)
FOREACH(class ${VTK_IO_CLASSES_ABSTRACT})
  SET(VTK_CLASS_ABSTRACT_${class} 1)
ENDFOREACH(class)
FOREACH(class ${VTK_IO_CLASSES_WRAP_EXCLUDE})
  SET(VTK_CLASS_WRAP_EXCLUDE_${class} 1)
ENDFOREACH(class)
