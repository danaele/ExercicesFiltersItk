//Median Filter Binary Image

#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include <iostream>
#include "MedianFilterImageCLP.h"
#include "itkMedianImageFilter.h"


int main( int argc , char *argv[] )
{
  PARSE_ARGS ;

  // Image Type
    typedef unsigned char PixelType;
    typedef itk::Image< PixelType, 2 > ImageType;
  
    //Read Image
    typedef itk::ImageFileReader<ImageType> ReaderType;
    ReaderType::Pointer reader = ReaderType::New();
    reader->SetFileName(input);
    reader->Update() ;

    //Write Image
    typedef itk::ImageFileWriter< ImageType > WriterType ;
    WriterType::Pointer writer = WriterType::New();

    //Median Filter
    typedef itk::MedianImageFilter< ImageType, ImageType > FilterType;
    FilterType::Pointer medianFilter = FilterType::New();

    ImageType::SizeType indexRadius;
    indexRadius[0] = radiusX; // radius along x
    indexRadius[1] = radiusY; // radius along y

    medianFilter->SetRadius( indexRadius );

    medianFilter->SetInput( reader->GetOutput() );
    medianFilter->Update();
    writer->SetInput( medianFilter->GetOutput() );
    writer->SetFileName(output) ;
    writer->Update();

    return EXIT_SUCCESS;
}
