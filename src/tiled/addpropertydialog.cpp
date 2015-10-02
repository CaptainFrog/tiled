#include "addpropertydialog.h"
#include "ui_addpropertydialog.h"

AddPropertyDialog::AddPropertyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPropertyDialog)
{
    ui->setupUi(this);

    // Add possible types from QVariant
    // TODO rename double to float
    ui->typeBox->addItem(QLatin1String(QVariant::typeToName(QVariant::Bool)));

    ui->typeBox->addItem(QLatin1String(QVariant::typeToName(QVariant::Int)));
    ui->typeBox->addItem(QLatin1String("Float"));

    // Rename QString, QSize and QPoint to something else
    ui->typeBox->addItem(QLatin1String("String"));    /* QString */
    ui->typeBox->addItem(QLatin1String("Size"));      /* QSize */
    ui->typeBox->addItem(QLatin1String("SizeF"));     /* QSizeF */
    ui->typeBox->addItem(QLatin1String("Point"));     /* QPoint */
    ui->typeBox->addItem(QLatin1String("PointF"));    /* QPointF */

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

    //Select String as Default
    ui->typeBox->setCurrentText(QLatin1String("String"));

}

AddPropertyDialog::~AddPropertyDialog()
{
    delete ui;
}

QString AddPropertyDialog::getPropertyName()
{
    return ui->name->text();
}

QVariant::Type AddPropertyDialog::getPropertyType()
{
    QString typeText = ui->typeBox->currentText();
    if(typeText == QLatin1String("Float")){ return QVariant::Double;}
    if(typeText == QLatin1String("String")){ return QVariant::String;}
    if(typeText == QLatin1String("Size")){ return QVariant::Size;}
    if(typeText == QLatin1String("SizeF")){ return QVariant::SizeF;}
    if(typeText == QLatin1String("Point")){ return QVariant::Point;}
    if(typeText == QLatin1String("PointF")){ return QVariant::PointF;}
    return QVariant::nameToType(typeText.toLatin1().constData());
}

void AddPropertyDialog::on_name_textChanged(const QString &arg1)
{
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(!arg1.isEmpty());
}
