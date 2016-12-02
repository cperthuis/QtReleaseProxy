#include "../include/QtReleaseProxy.h"

namespace QtReleaseProxy
{

	ModelIndexList::ModelIndexList(const QModelIndexList &modelIndexList) :modelIndexList(modelIndexList)
	{
	}
	
	ModelIndexList *createModelIndexList(const QItemSelection &itemSelection)
	{
		ModelIndexList *modelIndexList = new ModelIndexList(itemSelection.indexes());
		return modelIndexList;
	}

	void destroyModelIndexList(ModelIndexList* modelIndexList)
	{
		delete modelIndexList;
	}

}
