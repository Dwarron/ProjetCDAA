#ifndef CREATIONFICHEWINDOW_H
#define CREATIONFICHEWINDOW_H

/**
 * \file CreationFicheWindow.h
 * \class CreationFicheWindow CreationFicheWindow.h
 * \brief Fenetre qui permet de creer la fiche d'un contact
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include <QWidget>

namespace Ui { class CreationFicheWindow; }

class CreationFicheWindow : public QWidget
{
    Q_OBJECT

public:
    CreationFicheWindow(QWidget* parent = nullptr);
    ~CreationFicheWindow();

protected:
    void resizeEvent(QResizeEvent*) override;

private:
    Ui::CreationFicheWindow* ui;
    QString file_name;

private slots:
    void creationFiche();
    void selectFile();
    void showImage(QString path);

signals:
     void imageSelected(QString);
     void contactCreated(std::string, std::string, std::string, std::string, std::string, std::string);
};

#endif // CREATIONFICHEWINDOW_H
