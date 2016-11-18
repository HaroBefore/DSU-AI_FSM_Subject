#pragma once

enum eLocationType
{
	locationHome,
	locationCompany,
	locationSubway,
	locationSeoMyeon,
	locationNamPo,
	locationHaeundae
};

inline string GetNameOfLocation(eLocationType location)
{
	switch (location)
	{
	case locationHome:			return "��";
	case locationCompany:		return "ȸ��";
	case locationSubway:		return "����ö";
	case locationSeoMyeon:		return "����";
	case locationNamPo:			return "����";
	case locationHaeundae:		return "�ؿ��";
	default:					return "UNKOWN";
	}
}