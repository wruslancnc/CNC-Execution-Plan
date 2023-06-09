#ifndef CONFIGUREDIALOG_H
#define CONFIGUREDIALOG_H

#include <QDialog>
#include "ui_configuredialog.h"
#include "../../../inc/bdaqctrl.h"

using namespace Automation::BDaq;

struct ConfigureParameter 
{
	QString deviceName;
	int channelCount;
	int channelStart;
	ValueRange valueRange;
	double clockRatePerChan;
	int32	sectionLength;
	int cycles;
    QString profilePath;

	//for trigger
    TriggerAction triggerAction;
    SignalDrop triggerSource;
    ActiveSignal triggerEdge;
    int delayCount;
    double triggerLevel;

    //for trigger1
    TriggerAction trigger1Action;
    SignalDrop trigger1Source;
    ActiveSignal trigger1Edge;
    int delayCount1;
    double trigger1Level;
};

class ConfigureDialog : public QDialog
{
	Q_OBJECT

public:
	ConfigureDialog(QWidget *parent = 0);
	~ConfigureDialog();
	void Initailization();
	void CheckError(ErrorCode errorCode);
	ConfigureParameter GetConfigureParameter(){return configure;}
	void RefreshConfigureParameter();

private:
	Ui::ConfigureDialog ui;
	ConfigureParameter configure;
	bool isTriggerSupported;
    bool isTrigger1Supported;

private slots:
	void DeviceChanged(int index);
	void ButtonOKClicked();
	void ButtonCancelClicked();
	void TriggerSourceChanged(int index);
	void ButtonBrowseClicked();
};

#endif // CONFIGUREDIALOG_H
