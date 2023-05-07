opensite(){	
	lr_start_transaction("open_site");

	web_reg_save_param("userSession",
		"LB/IC=name=\"userSession\" value=\"",
		"RB=\"/>",
		LAST);
	web_reg_find("Text=Web Tours",
  	  LAST);
	
	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("open_site", LR_AUTO);
};
login(){
lr_start_transaction("login");

	web_revert_auto_header("Sec-Fetch-User");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");
	
	web_reg_find("Text/IC=User password was correct",
		LAST);

/*Correlation comment - Do not change!  Original value='welcome' Name ='page' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=page",
		"RegExp=A\\ HREF=\"(.*?)\\.pl",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='flights' Name ='in' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=in",
		"RegExp=images/(.*?)\\.gif",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='itinerary' Name ='page_1' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=page_1",
		"RegExp=page=(.*?)\"\\ TARGET",
		"Ordinal=2",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);

	web_reg_find("Text=Welcome to Web Tours",
   	 LAST);
    
  	  web_reg_find("Text=Welcome, <b>{username}</b>, to the Web Tours reservation pages",
 	   LAST);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={userSession}", ENDITEM, 
		"Name=username", "Value={username}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=login.x", "Value=67", ENDITEM, 
		"Name=login.y", "Value=10", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);

	lr_end_transaction("login",LR_AUTO);
};
gotoflights(){
lr_start_transaction("go_to_flights");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_reg_find("Text=User has returned to the search page.",
		LAST);

/*Correlation comment - Do not change!  Original value='roundtrip' Name ='.cgifields' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=.cgifields",
		"TagName=input",
		"Extract=name",
		"Type=checkbox",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/reservations.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='seatPref' Name ='Name' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=Name",
		"TagName=input",
		"Extract=name",
		"Type=radio",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/reservations.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='seatType' Name ='Name_1' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=Name_1",
		"TagName=input",
		"Extract=name",
		"Type=radio",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/reservations.pl*",
		LAST);

	web_url("Search Flights Button",
		"URL=http://localhost:1080/cgi-bin/{page}.pl?page=search",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home",
		"Snapshot=t10.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("go_to_flights",LR_AUTO);
};
logout(){
 lr_start_transaction("logout");

  web_add_header("Sec-Fetch-User", 
    "?1");

  web_add_header("Upgrade-Insecure-Requests", 
    "1");

  web_reg_find("Text=A Session ID has been created",
    LAST);
  
  web_url("SignOff Button", 
    "URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
    "TargetFrame=body", 
    "Resource=0", 
    "RecContentType=text/html", 
    "Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
    "Snapshot=t7.inf", 
    "Mode=HTML", 
    LAST);

  lr_end_transaction("logout",LR_AUTO);
};

