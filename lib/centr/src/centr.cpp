#include "centr.h"

void Centr::print_stations() {
  // create wifi_sta_list & tcpip_adapter_sta_list structs
  wifi_sta_list_t wifi_sta_list;
  tcpip_adapter_sta_list_t adapter_sta_list;

  // set bytes to zero on both structs
  memset(&wifi_sta_list, 0, sizeof(wifi_sta_list));
  memset(&adapter_sta_list, 0, sizeof(adapter_sta_list));

  // load connected stations into struct
  esp_wifi_ap_get_sta_list(&wifi_sta_list);

  // load adapters into struct using station struct
  tcpip_adapter_get_sta_list(&wifi_sta_list, &adapter_sta_list);

  // print out connections
  for (int i = 0; i < adapter_sta_list.num; i++) {
 
    tcpip_adapter_sta_info_t station = adapter_sta_list.sta[i];

    Serial.print("MAC: ");
    for(int i = 0; i< 6; i++){
      Serial.printf("%02X", station.mac[i]);  
      if(i<5)Serial.print(":");
    }
 
    Serial.print("\nIP: ");
    char ip[IP4ADDR_STRLEN_MAX];
    esp_ip4addr_ntoa(&station.ip, ip, IP4ADDR_STRLEN_MAX);

    Serial.println(ip);
  }
}