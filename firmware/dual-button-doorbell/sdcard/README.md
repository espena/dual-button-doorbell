# Sample configuration

## SD card formatting

The SD card must be FAT formatted. File names are restricted to 7.3-format: Up to 7 characters for the file name
and up to 3 characters for the file extension.

File system is not case sensitive. Stick to plain ANSI character set for file names.

## The config file

The configuration file is in JSON format. It is named _setting.jsn_ and must be located in the SD card's
root directory.

The current configuration file shows an example on how the system can be set up.

The behavior of each button (right or left) is configured here. Each button has a default mode and a
silent mode. Default is the normal mode, in which the regular doorbell sounds are played. Silent is
the night time mode, where you might want to choose a somewhat less noisy sound - like a door knock
or something.

Use cron syntax to notify when silent mode starts, and specify the duration in whole hours.

Default mode also have a _bell_ section. If you connect your regular door bell to the relay swith,
this setting governs how the door bell will be triggered (one time or multiple times,
and for how long each time).

### Wifi setup

Under the _wifi_ section of the config file, fill in SSID and password for your home network.
This must be a 2.4 GHz wireless network with WPA2 security.

### Date and time

The system uses [NTP](https://no.wikipedia.org/wiki/Network_Time_Protocol) to get correct time.

Your local time zone must be set correctly in the _datetime_ section of the config file.

Look up your time zone in [this table](https://github.com/nayarsystems/posix_tz_db/blob/master/zones.csv)
and enter the corresponding string value.

In the example configuration, the timezone is set for Norway (UTC+1 with daylight saving time enabled).

You can also choose to use another NTP service by editing the _server_ value under the _ntp_ section.

## The cron schedule

In addition to playing doorbell sounds, the system can be set up to play custom sound files at any given
time. Edit the _crontab.txt_ file to program the schedule.

Use regular [cron](https://en.wikipedia.org/wiki/Cron) syntax to describe either a single point in time
or a recurring interval.

The current _crontab.txt_ example file is programmed with an hourly chime that will be played
between 06 and 22 every day. It also includes a lullaby song that will be played 19:59:20 before
weekdays and 20:59:20 before saturdays and sundays.

The _crontab.txt_ file may contain up to 25 valid cron entries.

## MQTT setup

Edit the _mqtt_ section in the configuration file to enable push notifications for when someone pushes
one of the doorbell buttons. You will need access to a MQTT broker for this to work.

MQTT is TLS encrypted, and a CA (root) certificate is required for proper validation. The certificate
must be PEM formatted.

In this example _mqtt.pem_ is the certificate from Letsencrypt (R3). You are required to provide
a CA root certificate matching the certificate authority for your MQTT broker.

Self-signed certificates for home servers will work fine, as long as you copy a matching root
certificate on the SD card. Edit the _cert_file_ property so that it points to
the correct certificate.

You can also alter the MQTT topic that the system will use when posting notifications.

## Licenses

Sound assets in this directory are licensed under Creative Commons,
[Attribution 3.0 Unported](https://creativecommons.org/licenses/by/3.0/).

The example clips are downloaded from [freesound.org](https://freesound.org/),
and attributions are as follows:

* _bell01.wav_ [Doorbell A](https://freesound.org/people/kwahmah_02/sounds/275072/) by kwahmah_02
* _bell02.wav_ [Doorbell](https://freesound.org/people/jorickhoofd/sounds/177875/) by jorickhoofd
* _knock.wav_ [Knock_on_door.wav](https://freesound.org/people/Philip_Daniels/sounds/244325/) by Philip_Daniels
* _ding.wav_ [Hand Bells, F, Single.wav](https://freesound.org/people/InspectorJ/sounds/339816/) by InspectorJ
* _lullaby.wav_ [Brahms' Lullaby](https://freesound.org/people/nlux/sounds/621586/) by nlux
