Action()
{
	lr_start_transaction("2_script_delete_reservation");

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	opensite();
	
	
	lr_think_time(5);
	
	login();
	
	lr_think_time(5);
	lr_start_transaction("Check_ticket");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_reg_find("Text= User wants the intineraries.",
		LAST);

	web_url("Itinerary Button",
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home",
		"Snapshot=t4.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("Check_ticket",LR_AUTO);

	
	
	lr_think_time(5);
	lr_start_transaction("Cancel_reservation");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_header("Sec-Fetch-Dest", 
		"frame");

	web_add_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_reg_find("Text=Flights List",
		LAST);

	
	
	web_submit_form("itinerary.pl", 
    "Snapshot=t100.inf", 
    ITEMDATA, 
    "Name=1", "Value=on", ENDITEM,  
    "Name=2", "Value=on", ENDITEM, //�������� 2 �����
   
    //"Name=3", "Value=on", ENDITEM, // �������� 3 �����
    "Name=removeFlights.x", "Value=72", ENDITEM, 
    "Name=removeFlights.y", "Value=1", ENDITEM, 
    LAST);

	lr_end_transaction("Cancel_reservation",LR_AUTO);

	
	
	lr_think_time(5);
	
	logout();
	

	lr_end_transaction("2_script_delete_reservation", LR_AUTO);
	
	return 0;
}