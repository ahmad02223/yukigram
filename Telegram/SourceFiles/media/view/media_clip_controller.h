/*
This file is part of Telegram Desktop,
the official desktop version of Telegram messaging app, see https://telegram.org

Telegram Desktop is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

It is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

In addition, as a special exception, the copyright holders give permission
to link the code of portions of this program with the OpenSSL library.

Full license: https://github.com/telegramdesktop/tdesktop/blob/master/LICENSE
Copyright (c) 2014-2016 John Preston, https://desktop.telegram.org
*/
#pragma once

namespace Ui {
class LabelSimple;
class FadeAnimation;
class IconButton;
} // namespace Ui

struct AudioPlaybackState;

namespace Media {
namespace Clip {

class Playback;
class VolumeController;

class Controller : public TWidget {
	Q_OBJECT

public:
	Controller(QWidget *parent);

	void showAnimated();
	void hideAnimated();

	void updatePlayback(const AudioPlaybackState &playbackState);
	void setInFullScreen(bool inFullScreen);

signals:
	void playPressed();
	void pausePressed();
	void seekProgress(int64 position);
	void seekFinished(int64 position);
	void volumeChanged(float64 volume);
	void toFullScreenPressed();
	void fromFullScreenPressed();

private slots:
	void onSeekProgress(int64 position);
	void onSeekFinished(int64 position);

protected:
	void resizeEvent(QResizeEvent *e) override;
	void paintEvent(QPaintEvent *e) override;

private:
	bool _showPause = false;
	int64 _seekPosition = -1;

	ChildWidget<Ui::IconButton> _playPauseResume;
	ChildWidget<Playback> _playback;
	ChildWidget<VolumeController> _volumeController;
	ChildWidget<Ui::IconButton> _fullScreenToggle;
	ChildWidget<Ui::LabelSimple> _playedAlready;
	ChildWidget<Ui::LabelSimple> _toPlayLeft;

	std_::unique_ptr<Ui::FadeAnimation> _fadeAnimation;

};

} // namespace Clip
} // namespace Media
