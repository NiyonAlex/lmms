#ifndef GROOVEEXPERIMENTS_H
#define GROOVEEXPERIMENTS_H

#include <QObject>

#include "AutomatableSlider.h"
#include "Groove.h"
#include "lmms_basics.h"
#include "MidiTime.h"
#include "Note.h"
#include "Pattern.h"

/**
 * A groove thats new
 */
class GrooveExperiments : public Groove
{
	Q_OBJECT
public:
	GrooveExperiments(QObject *parent=0 );

	virtual ~GrooveExperiments();

	void init();

	int isInTick(MidiTime * _cur_start, const fpp_t _frames, const f_cnt_t _offset, Note * _n, Pattern * _p );

	inline virtual QString nodeName() const
	{
		return "experiment";
	}



	QWidget * instantiateView( QWidget * _parent );

public slots:
	// valid values are from 0 - 127
	void update();

private:
	int m_frames_per_tick;
} ;

class GrooveExperimentsView : public QWidget
{
	Q_OBJECT
public:
	GrooveExperimentsView(GrooveExperiments * _m_ge, QWidget * parent=0 );
	~GrooveExperimentsView();

public slots:
	void modelChanged();
	void valueChanged(int);

private:
	GrooveExperiments * m_ge;
	IntModel * m_sliderModel;
	AutomatableSlider * m_slider;

} ;

#endif // GROOVEEXPERIMENTS_H
