#ifndef _234218_WET1_
#define _234218_WET1_
#include "AVLTree.h"
#include"Fruit.h"
#include "Tree.h"
#include "FieldManager.h"
//#include "AVLTree.h"
//#include"Fruit.h"
//#include "Tree.h"
#include "FieldManager.h"
#include "StatusType.h"
#ifdef __cplusplus
extern "C" {
#endif

	int fieldSize;

	int calculateTreeNum(int i, int j)
	{
		return i * fieldSize + j;
	}

	 /* Description:   Initiates the data structure.
	  * Input:         DS - A pointer to the data structure.
	  * 			N - size of field
	  * Output:        None.
	  * Return Values: A pointer to a new instance of the data structure - as a void* pointer.
	  */
	void* Init(int N)
	{
		fieldSize = N;
		return new FieldManager();
	}

	/* Description:   Plants a tree in the (i,j) location inside the field.
	 * Input:         DS - A pointer to the data structure.
	 *                i - The row to plant the tree in.
	 *                j - The spot to plant the tree inside the row.
	 * Output:        None.
	 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
	 *                INVALID_INPUT - If DS==NULL or if i,j are not in [0,N-1]
	 *                FAILURE - If a tree already exists in the spot
	 *                SUCCESS - Otherwise.
	 */
	StatusType PlantTree(void* DS, int i, int j)
	{
		
		if (DS == NULL || i<0 || i> fieldSize - 1 || j<0 || j>fieldSize - 1)
		{
			return INVALID_INPUT;
		}
		if (((FieldManager*)DS)->findTree(calculateTreeNum(i,j)) != NULL )
		{
			return FAILURE;
		}
		((FieldManager*)DS)->plantTree(calculateTreeNum(i,j));

		return SUCCESS;
	}

	/* Description:   Adds a fruit to (i,j)'th tree.
	 * Input:         DS - A pointer to the data structure.
	 *                i - The tree's row
	 *                j - The tree's spot inside the row
	 *                fruitID - the unique fruit's ID.
	 *                ripeRate - the ripeness level of the fruit.
	 * Output:        None.
	 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
	 *                INVALID_INPUT - If DS==NULL or if i,j are not in [0,N-1]
	 *                				or if fruitID<=0, or if ripeRate<=0
	 *                FAILURE -	If fruitID is already used, or the (i,j)'th tree doesn't exist
	 *                SUCCESS - Otherwise.
	 */


	StatusType AddFruit(void* DS, int i, int j, int fruitID, int ripeRate)
	{
		if (DS == NULL || i<0 || i> fieldSize - 1 || j<0 || j>fieldSize - 1 || fruitID <= 0|| ripeRate <= 0)
		{
			return INVALID_INPUT;
		}
		if (((FieldManager*)DS)->findFruitByID(fruitID) != NULL || ((FieldManager*)DS)->findTree(calculateTreeNum(i, j)) == NULL)
		{
			return FAILURE;
		}
		((FieldManager*)DS)->addFruit(calculateTreeNum(i, j), fruitID, ripeRate);
		return SUCCESS;
	}


	/* Description:   Removes a fruit from the tree
	 * Input:         DS - A pointer to the data structure.
	 *                fruitID - the unique fruit's ID.
	 * Output:        None.
	 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
	 *                INVALID_INPUT - If DS==NULL or if fruitID<=0
	 *                FAILURE -	If fruitID doesn't exist
	 *                SUCCESS - Otherwise.
	 */



	StatusType PickFruit(void* DS, int fruitID)
	{
		if (DS == NULL || fruitID <= 0)
		{
			return INVALID_INPUT;
		}
		if (((FieldManager*)DS)->findFruitByID(fruitID) == NULL )
		{
			return FAILURE;
		}
		((FieldManager*)DS)->pickFruit(fruitID);
		return SUCCESS;

	}

	/* Description:   Updated a fruit's ripeness
	 * Input:         DS - A pointer to the data structure.
	 *                fruitID - the unique fruit's ID.
	 *                ripeRate - the ripeness level of the fruit.
	 * Output:        None.
	 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
	 *                INVALID_INPUT - If DS==NULL or if fruitID<=0, or if ripeRate<=0
	 *                FAILURE -	If fruitID doesn't exist
	 *                SUCCESS - Otherwise.
	 */
	StatusType RateFruit(void* DS, int fruitID, int ripeRate)
	{
		if (DS == NULL || fruitID <= 0 || ripeRate <= 0)
		{
			return INVALID_INPUT;
		}
		if (((FieldManager*)DS)->findFruitByID(fruitID) == NULL)
		{
			return FAILURE;
		}
		((FieldManager*)DS)->RateFruit(fruitID, ripeRate);
		return SUCCESS;

	}

	/* Description:   Returns the best fruit in the (i,j)'th tree, by ripeness
	 * Input:         DS - A pointer to the data structure.
	 *                i - The tree's row
	 *                j - The tree's spot inside the row
	 * Output:        fruitID - A pointer to a variable that should be updated to the ID of the best fruit,
	 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
	 *                INVALID_INPUT - If DS==NULL or if fruitID == NULL or if i,j are not in [0,N-1]
	 *                FAILURE - If the (i,j)'th tree doesn't exist
	 *                SUCCESS - Otherwise.
	 */
	StatusType GetBestFruit(void* DS, int i, int j, int* fruitID)
	{
		if (DS == NULL || fruitID == NULL || i<0 || i> fieldSize - 1 || j<0 || j>fieldSize - 1)
		{
			return INVALID_INPUT;
		}

		if (((FieldManager*)DS)->findTree(calculateTreeNum(i, j)) == NULL)
		{
			return FAILURE;
		}
		((FieldManager*)DS)->getBestFruit(calculateTreeNum(i, j),fruitID);
		return SUCCESS;
	}

	/* Description:   Returns all the fruits in the (i,j)'th tree sorted by their rate.
	 * Input:         DS - A pointer to the data structure.
	 *                i - The tree's row
	 *                j - The tree's spot inside the row
	 * Output:        fruits - A pointer to a to an array that you should update with the fruits' IDs sorted by their rates,
	 *			in case two fruits have the same download count they should be sorted by their ID.
	 *                numOfFruits - A pointer to a variable that should be updated to the number of fruits.
	 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
	 *                INVALID_INPUT - If any of the arguments is NULL or if i,j are not in [0,N-1]
	 *                FAILURE - If the (i,j)'th tree doesn't exist
	 *                SUCCESS - Otherwise.
	 */
	StatusType GetAllFruitsByRate(void* DS, int i, int j, int* fruits, int* numOfFruits)
	{
		if (DS == NULL || i<0 || i> fieldSize - 1 || j<0 || j>fieldSize - 1 || fruits == NULL || numOfFruits == NULL)
		{
			return INVALID_INPUT;
		}
		if (((FieldManager*)DS)->findTree(calculateTreeNum(i, j)) == NULL)
		{

			return FAILURE;
		}
		fruits = ((FieldManager*)DS)->GetAllFruitsByRate(calculateTreeNum(i, j));
		*numOfFruits = ((FieldManager*)DS)->getTreeSize(calculateTreeNum(i, j));
		return SUCCESS;
	}

	/* Description:   Updates the ripeness of the fruits where fruitID % rottenBase == 0.
	 * 				  For each matching fruit, multiplies its ripeness level by multiplyFactor.
	 * Input:         DS - A pointer to the data structure.
	 *                rottenBase - The base for the modulo.
	 *		  		  rottenFactor - The multiply factor.
	 * Output:        None.
	 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
	 *                INVALID_INPUT - If DS==NULL or if rottenBase < 1 or if rottenFactor < 1
	 *                SUCCESS - Otherwise.
	 */
	StatusType UpdateRottenFruits(void* DS, int rottenBase, int rottenFactor)
	{
		if (DS == NULL || rottenBase < 1 || rottenFactor < 1){

			return INVALID_INPUT;
		}
		((FieldManager*)DS)->UpdateRottenFruits(rottenBase, rottenFactor);

		return SUCCESS;
	}

	/* Description:   Quits and deletes the database.
	 *                DS should be set to NULL.
	 * Input:         DS - A pointer to the data structure.
	 * Output:        None.
	 * Return Values: None.
	 */
	void Quit(void** DS) {
		((FieldManager*)DS)->deleteField();
	};

#ifdef __cplusplus
}
#endif

#endif    /*_234218_WET1_ */ 

