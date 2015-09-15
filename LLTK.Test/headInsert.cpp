#include "stdafx.h"
#include "CppUnitTest.h"

#include "LLToolKit.h"
#include "Node.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LLTKTest
{		
	TEST_CLASS(headInsesrt)
	{
	public:
		
		TEST_METHOD(LLTK_headInsert_insertingNewHead_NodeIsInserted)
		{
			// Arrange
			Node<int>* n3 = new Node<int>(1);
			Node<int>* n2 = new Node<int>(2, n3);
			Node<int>* headPtr = new Node<int>(3, n2);

			LLTK::LLToolkit<int> toolkit;

			// Act
			toolkit.headInsert(headPtr, 4);

			// Assesrt
			Assert::AreEqual(headPtr->info, 4);
		}

		TEST_METHOD(LLTK_headInsert_insertFromNullPtr_NodeIsInserted)
		{
			// Arrange
			Node<int>* headPtr = nullptr;
			LLTK::LLToolkit<int> toolkit;

			// Act
			toolkit.headInsert(headPtr, 1);

			//Assert
			Assert::AreEqual(headPtr->info, 1);
		}
	};
}