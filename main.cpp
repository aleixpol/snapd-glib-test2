#include <QCoreApplication>
#include <Snapd/Client>
#include <Snapd/Snap>
#include <QDebug>

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);

    QSnapdClient m_client;
    const QScopedPointer<QSnapdFindRequest> snapreq(m_client.find(QSnapdClient::FindFlag::None, "okular"));
    snapreq->runSync();

    for (int i=0, c=snapreq->snapCount(); i<c; ++i) {
        QSharedPointer<QSnapdSnap> snap(snapreq->snap(i));
        qDebug() << "snap:" << snap->name() << ", channels:" << snap->channelCount();
    }

    return app.exec();
}
