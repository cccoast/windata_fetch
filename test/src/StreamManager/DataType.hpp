

#ifndef STREAM_DATE_TYPE_H
#define STREAM_DATE_TYPE_H

#define STREAMTYPE_FUTURE 0x1303
#define STREAMTYPE_STOCK  0x2134

typedef double PriceType;
typedef int32_t   VolumeType;
typedef char   InstrumentIDType[31];
typedef double MoneyType;
typedef double LargeVolumeType;
typedef int    StreamInfoType;
typedef double RatioType;
typedef char   TimeType[9]; //TODO: Need Improvement
typedef int    MillisecType;
typedef long   WholeTimeType; //120101300 hhmmssmmm

#endif
