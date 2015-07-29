#ifndef __itkMultiThreadedImageFilter_hxx
#define __itkMultiThreadedImageFilter_hxx

#include "MultiThreadImageFilter.h"

#include "itkObjectFactory.h"
#include "itkImageRegionIterator.h"
#include "itkImageRegionConstIterator.h"
#include <iostream>

namespace itk
{

  template< class TImage>
  void MultiThreadedImageFilter< TImage>::ThreadedGenerateData(const OutputImageRegionType & region, ThreadIdType threadId)
  {
    std::cout << "Thread " << threadId << " given region: " << region << std::endl;

    typename TImage::ConstPointer input = this->GetInput();
    typename TImage::Pointer output = this->GetOutput();

    //iterators
    typedef itk::ImageRegionConstIterator< TImage > ConstIteratorType;
    typedef itk::ImageRegionIterator<TImage > IteratorType;

    ConstIteratorType constIterator( input, input->GetRequestedRegion() );
    IteratorType iterator( output, output->GetRequestedRegion() );
    //this->AllocateOutputs(); //No useful for threaded method but necessary for non threaded methode (generateData)
    constIterator.GoToBegin();
    iterator.GoToBegin();
    while(!constIterator.IsAtEnd())
      {
        //Lighten Image
        if(constIterator.Get()<=155)
          {
            iterator.Set(constIterator.Get() + 100);
          }
        else
          {
            iterator.Set(constIterator.Get() );
          }
        ++iterator;
        ++constIterator;
      }
  }
}// end namespace


#endif
