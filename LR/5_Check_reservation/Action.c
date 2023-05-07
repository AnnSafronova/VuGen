Action()
{
	lr_start_transaction("5_Skript_Check_reservation");

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


	
	web_set_sockets_option("SSL_VERSION", "2&3");
	
	
	lr_think_time(5);

	login();

	

	
	lr_think_time(5);
	
	lr_start_transaction("Check_ticket");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_reg_find("Text=User wants the intineraries",
		LAST);

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Check_ticket", LR_AUTO);
	
	
	
lr_think_time(5);
logout();
	

	lr_end_transaction("5_Skript_Check_reservation", LR_AUTO);

	return 0;
}