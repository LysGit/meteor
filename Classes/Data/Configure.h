//
//  Configure.h
//  meteor
//
//  Created by 罗耀生 on 14-6-29.
//
//

#ifndef meteor_Configure_h
#define meteor_Configure_h

#define NF_ADD_STAR         "Notification_add_starNode"
#define NF_DEL_STAR         "Notification_delete_starNode"
#define NF_SHOOT_BULLET     "Notification_shoot_bullet"
#define NF_BULLET_MOVING    "Notification_shoot_moving"
#define NF_DEL_BULLET      "Notification_delete_shoot"


#define NF_MENU_REFRESH      "Notification_menu_refresh"
#define NF_MENU_RECOVER      "Notification_menu_recover"
#define NF_MENU_SHARE      "Notification_menu_share"


#define WEATHER_OVERCASTSKY "weather_overcast"//阴天
#define WEATHER_SUNSHINE "weather_sunshine"//晴天
#define WEATHER_CLOUDY "weather_cloudy"//多云
#define WEATHER_FLURRY "weather_flurry"//小雨
#define WEATHER_ModerateRain "weather_moderateRain"//中雨
#define WEATHER_HEAVYRAIN "weather_heavyRain"//大雨
#define WEATHER_RAINSTORM "weather_rainstorm"//暴雨
#define WEATHER_GUST "weather_gust"//阵风
#define WEATHER_BREEZE "weather_breeze"//微风

#define WEATHER_TYPHOON "weather_typhoon"//台风
#define WEATHER_TORNADO "weather_tornado"//龙卷风
#define WEATHER_FOG "weather_fog"//雾
#define WEATHER_SONW "weather_sonw"//雪
#define WEATHER_FRONST "weather_frost"//霜
#define WEATHER_HAIL "weather_hail"//冰雹


enum {
    PSQ_Emty = 0,
    PSQ_Moving,
    PSQ_Stop,
    PSQ_Die,
} ;

#endif
