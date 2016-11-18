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
	case locationHome:			return "집";
	case locationCompany:		return "회사";
	case locationSubway:		return "지하철";
	case locationSeoMyeon:		return "서면";
	case locationNamPo:			return "남포";
	case locationHaeundae:		return "해운대";
	default:					return "UNKOWN";
	}
}