//Create our own filter
//ITK exercise

//Median Filter Binary Image

#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include <iostream>
#include "MultiThreadImageFilter.hxx"
#include "MultiThreadImageFilterCLP.h"



int main( int argc , char *argv[] )
{
    PARSE_ARGS ;

  // Image Type
    typedef unsigned char PixelType;
    typedef itk::Image< PixelType, 2 > ImageType;
    typedef itk::MultiThreadedImageFilter<ImageType>  FilterType;
    //Read Image
    typedef itk::ImageFileReader<ImageType> ReaderType;
    ReaderType::Pointer reader = ReaderType::New();
    reader->SetFileName(input);
    reader->Update() ;

    //Write Image
    typedef itk::ImageFileWriter< ImageType > WriterType ;
    WriterType::Pointer writer = WriterType::New();

    //Filter Type 
    FilterType::Pointer ownFilter = FilterType::New();
    ownFilter->SetInput(reader->GetOutput());
    ownFilter->Update();

    writer->SetInput( ownFilter->GetOutput() );
    writer->SetFileName(output) ;
    writer->Update();

    return EXIT_SUCCESS;
}
