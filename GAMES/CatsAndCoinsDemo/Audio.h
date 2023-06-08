#pragma once

#include "Globals.h"

const uint16_t jumpSound[] =
{
	(1 << 8) + (21 << 2),
	0
};

const uint16_t landSound[] =
{
	(1 << 8) + (2 << 2),
	0
};

const uint16_t killSound[] =
{
	(1 << 8) + (14 << 2),
	0
};

const uint16_t coinSound[] =
{
	(1 << 8) + (26 << 2),
	(1 << 8) + (30 << 2),
	(1 << 8) + (33 << 2),
	0
};
extern int8_t coinSoundTrack;

const uint16_t painSound[] =
{
	(1 << 8) + (25 << 2),
	(1 << 8) + (22 << 2),
	(1 << 8) + (19 << 2),
	0
};

const uint16_t nextSound[] =
{
	(1 << 8) + (31 << 2),
	0
};

const uint16_t okSound[] =
{
	(1 << 8) + (27 << 2),
	(1 << 8) + (31 << 2),
	(1 << 8) + (34 << 2),
	0
};