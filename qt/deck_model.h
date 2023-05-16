#ifndef DECKMODEL_H
#define DECKMODEL_H

#include <QAbstractListModel>
#include <vector>
#include <memory>
#include "IDeck.h"
#include "word_cards.h"

class DeckModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum DeckRoles {
      CardRole = Qt::UserRole + 1
    };

    explicit DeckModel(std::shared_ptr<IDeck> deck, QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    int indexOfWord(const QString& word);
    QModelIndex index(int row, int column = 0, const QModelIndex &parent = QModelIndex()) const override;

public slots:
    void load(const QString& word);
    void next(const QModelIndex& index);
    void prev(const QModelIndex& index);

private:
    std::shared_ptr<IDeck> deck;
};

#endif // DECKMODEL_H
