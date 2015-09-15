#include "stdafx.h"
#include "CppUnitTest.h"

#include "Node.hpp"
#include "LLToolKit.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LLTKTest
{
	TEST_CLASS(headRemove)
	{
	public:
		
		TEST_METHOD(LLTK_headRemove_removeHeadElement_headIsRemoved)
		{
			// Arrange
			Node<int>* n3 = new Node<int>(1);
			Node<int>* n2 = new Node<int>(2, n3);
			Node<int>* headPtr = new Node<int>(3, n2);

			LLTK::LLToolkit<int> toolkit;

			// Act
			toolkit.headRemove(headPtr);

			// Assert
			Assert::AreEqual(headPtr->info, 2);
		}

	};
}