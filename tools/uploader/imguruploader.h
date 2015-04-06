#ifndef IMGURUPLOADER_H
#define IMGURUPLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "imageuploader.h"

class ImgurUploader : public ImageUploader
{
Q_OBJECT

public:
  ImgurUploader(QVariantHash &options);

public slots:
  void upload(const QString &fileName);
  void cancel();

private slots:
  void finished();
  void uploadProgress(qint64 bytesReceived, qint64 bytesTotal);
  void networkError(QNetworkReply::NetworkError code);

signals:
  void cancelRequest();

private:
  void uploadAnonymous(const QString &fileName);

};

#endif // IMGURUPLOADER_H
