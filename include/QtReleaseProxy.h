#pragma once

#include <QtCore/QAbstractItemModel>
#include <QtCore/QItemSelectionModel>

#ifdef QTRELEASEPROXY_LIB
#define QTRELEASEPROXY_API __declspec(dllexport)
#else
#define QTRELEASEPROXY_API __declspec(dllimport)
#endif


namespace QtReleaseProxy
{

	struct ModelIndexList
	{
		QModelIndexList modelIndexList;
		ModelIndexList(const QModelIndexList &modelIndexList);
	};

	QTRELEASEPROXY_API ModelIndexList *createModelIndexList(const QItemSelection &itemSelection);
	QTRELEASEPROXY_API void destroyModelIndexList(ModelIndexList* modelIndexList);

}
