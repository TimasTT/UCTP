#include "blockservice.h"
#include "objects/block.h"
#include <TreeFrogModel>


void BlockService::index()
{
    auto blockList = Block::getAll();
    texport(blockList);
}

void BlockService::show(int id)
{
    auto block = Block::get(id);
    texport(block);
}

int BlockService::create(THttpRequest &request)
{
    auto items = request.formItems("block");
    auto model = Block::create(items);

    if (model.isNull()) {
        QString error = "Failed to create.";
        texport(error);
        return -1;
    }

    QString notice = "Created successfully.";
    tflash(notice);
    return model.id();
}

void BlockService::edit(TSession& session, int id)
{
    auto model = Block::get(id);
    if (!model.isNull()) {
        auto block = model.toVariantMap();
        texport(block);
    }
}

int BlockService::save(THttpRequest &request, TSession &session, int id)
{
    auto model = Block::get(id);
    
    if (model.isNull()) {
        QString error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        return 0;
    }

    auto block = request.formItems("block");
    model.setProperties(block);
    if (!model.save()) {
        texport(block);
        QString error = "Failed to update.";
        texport(error);
        return -1;
    }

    QString notice = "Updated successfully.";
    tflash(notice);
    return 1;
}

bool BlockService::remove(int id)
{
    auto block = Block::get(id);
    return block.remove();
}

