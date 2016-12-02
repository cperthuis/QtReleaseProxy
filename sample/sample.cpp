#include <QtWidgets>

#include <QtReleaseProxy.h>

class QMyWidget : public QWidget
{
	Q_OBJECT
public:
	QMyWidget(QWidget *parent = NULL);
	~QMyWidget();

	void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

private:
	QTreeView* _treeView;
};

QMyWidget::QMyWidget()
{
	_treeView = new QTreeView(this);
	QFileSystemModel *model = QFileSystemModel;
	_treeView->setModel(model);

	connect(_treeView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &QMyWidget::selectionChanged);
}


//QModelIndexList sample:
void QMyTreeWidget::selectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
	//QModelIndexList treeItemsSelected = selected.indexes(); 
	//This would crash in the destructor in Debug, need to use our QtReleaseProxy for the debug target to always do those memory operations with the Release version of Qt
	//Instead:

	QtReleaseProxy::ModelIndexList *proxy = QtReleaseProxy::createModelIndexList(selected);
	QModelIndexList &treeItemsSelected = proxy->modelIndexList;
	//...
	QtReleaseProxy::destroyModelIndexList(proxy);
}

