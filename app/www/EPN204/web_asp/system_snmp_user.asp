<html>
<head>
<meta http-equiv="Pragma" content="no-cache">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<link rel="stylesheet" href="style.css" type="text/css">
<title></title>
<SCRIPT language=JavaScript src=utils.js></SCRIPT>
<SCRIPT language=JavaScript src=spec.js></SCRIPT>
<SCRIPT language=JavaScript src=valid.js></SCRIPT>
<SCRIPT language=JavaScript src=navigatortab.js></SCRIPT>
<script language=JavaScript>
pageTitle();

var webVars = new Array( <% CGI_GET_WEB_CONST(); %>);
var syssnmp_user = new Array(<% CGI_SYS_SNMP_USER(); %>);
/*
just for test
var webVars = new Array( 'EPN104', '0', '0');
var syssnmp_user = new Array('a;b;c;d;0;1;2;2;3;user1;group1;1;user2;group2;2;;group3;2;user4;group4;1');			
*/
//var grupnum_INDEX=0;
var usernumber_INDEX=8;
var group_INDEX=9;
var MAX_USER_COUNT=4;//显示4个用户

function get_value(INDEX)
{
	if (syssnmp_user.length > 0)
	{
		var vs = syssnmp_user[0].split(';');
		if (vs.length > 0) return vs[INDEX];
	}
	return false;
}

var snmp_user_num=get_value(usernumber_INDEX);
var snmp_user_name=new Array(MAX_USER_COUNT);
var snmp_group_name=new Array(MAX_USER_COUNT);
var snmp_user_security=new Array(MAX_USER_COUNT);

function get_build(num)
{	var va;
	for(var i=0;i<num;i++)
	{
		snmp_user_name[i] = get_value(group_INDEX+i*3);
		snmp_group_name[i] = get_value(group_INDEX+i*3+1);
		va=parseInt(get_value(group_INDEX+i*3+2));
		if(0==va)
		snmp_user_security[i] = "不认证不加密";	
		if(1==va)
		snmp_user_security[i] = "只认证不加密";	
		if(2==va)
		snmp_user_security[i] = "既认证又加密";	
	}
}

get_build(MAX_USER_COUNT);

function selet_password_mode(password_mode,enpassword_mode)
{
	var str=new String("");
		str+='<table width=100% border=0 align=center cellpadding=5 cellspacing=1 bgcolor="#FFFFFF">';
		if(password_mode==1)
		{
			str+='<tr>';		
			str+='<td width=30% class=bgblue>认证模式</td>';
			str+='<td width=70% class=bggrey><select name="SNMP_USER_APMODE"  style="WIDTH: 228px">';
			str+='<option>MD5</option>';
			str+='</select>';
			str+='</td>';
			str+='</tr>';
			str+='<tr>';
			str+='     <td class=bgblue>认证密码</td>';
			str+='	   <td class=bggrey> <input type="password" size="34" id="SNMP_USER_PASSWORD" name="SNMP_USER_PASSWORD" id="2" maxlength="32" >(8~32字符)</TD> ';
			str+='</tr>';
			str+='<tr>';
			str+='		<td class=bgblue>确认认证密码</td>';
			str+='		<td class=bggrey><input type="password" size="34" id="txt2" name="SNMP_USER_PASSWORD_CON" maxlength="32" >(8~32字符)</TD>'; 
			str+='</tr>';
		}
		if(enpassword_mode==1)
		{
			str+='<tr>';
			str+='	<td class=bgblue>加密模式</td>';
			str+='	<td class=bggrey><select name="SNMP_USER_PASSWORDMODE"   style="WIDTH: 228px">';
			str+='	<option>DES</option>';
			str+='	</select></td>';
			str+='</tr>';
			str+='<tr>';
			str+='		<td class=bgblue>加密密码</td>';
			str+='		<td class=bggrey><input type="password" size="34" id="txt2" name="SNMP_USER_ENPASSWORD"  maxlength="32">(8~32字符)</TD> ';
			str+='</tr>';
			str+='<tr>';
			str+='		<td class=bgblue>确认加密密码</td>';
			str+='		<td class=bggrey><input type="password" size="34" id="txt2" name="SNMP_USER_ENPASSWORD_EN"  maxlength="32">(8~32字符)</TD>'; 
			str+='</tr>';
		}
		str+='<tr>';
		str+='<td width=100% class=bggrey colspan=2>&nbsp</td>';
		str+='</tr>';		    
		/*str +='<TR><TD height=250></TD></TR>'; */
		str+='</table>';	
		document.getElementById('selet_passwordmode').innerHTML = str;
}

function selet_security()
{
	var	f = document.forms[0];
	if(f.SNMP_USER_SAFE.value == 0) 
	{	
		selegroup(0);
		selet_password_mode(0,0);
	}
	else if(f.SNMP_USER_SAFE.value == 1) 
	{
		selegroup(1);
		selet_password_mode(1,0);
	}
	else if(f.SNMP_USER_SAFE.value == 2) 
	{	
		selegroup(2);
		selet_password_mode(1,1);
	}
}
function selegroup(safe)
{
	var str=new String("");
	var groupnum=4;//有多少个组
	var groupname="";
	str ='<table width=100% border=0 align=center cellpadding=5 cellspacing=1 bgcolor="#FFFFFF">'
	str +='<tr>';
	
	str +=' <td width=30% class=bgblue>用户所在组</td> ';
	str +='	<td width=70% class=bggrey><select name="SNMP_USER_INGROUP" style="WIDTH: 228px">';
	if(0==safe)//当用户的安全级别选择“不认证不加密”时，可以选择“不认证不加密”的组
	{
		for(var i=0;i<groupnum;i++)
		{	
			groupname=get_value(i);
			var group_security=get_value(i+4);
			if( groupname!='' && group_security == safe)
			str+="<option value="+groupname+ ">"+groupname+"</option>";
		}
	}
	else if(1==safe)
	{
		for(var i=0;i<groupnum;i++)
		{	
			groupname=get_value(i);
			var group_security=get_value(i+4);
			if( groupname!='' && (group_security == safe || group_security == 0 ))
			str+="<option value="+groupname+ ">"+groupname+"</option>";
		}
	}
	else //当用户的安全级别选择“既认证又加密”时，可以选择所有安全级别的组
	{
		for(var i=0;i<groupnum;i++)
		{	
			groupname=get_value(i);
			if(groupname!='')
			str+="<option value="+groupname+ ">"+groupname+"</option>";
		}
	}
	str +='</select></td>';	
	str +='	</tr>';
	str +='</table>	';
	
	document.getElementById('selet_groups').innerHTML = str;
}
function check_all_input()
{
	var f = document.forms[0];
	var string = "";
	var reg;
	string = f.SNMP_USER_NAME.value;
	reg = /^([0-9a-zA-Z,\,,\~,\!,\@,\$,\%,\^,\&,\*,\(,\),-,\_,\+,\=,\{,\},\[,\],\:,\|,\.,\?,\<,\>]{1,32})$/;
	if(-1 == string.search(reg))
	{
		alert("用户名不能输入非法字符:\\,\/,\",\',\;,#,空字符串,空格以及中文字符！");
		return false;		
	}
	
	reg = /^([0-9a-zA-Z,\,,\~,\!,\@,\$,\%,\^,\&,\*,\(,\),-,\_,\+,\=,\{,\},\[,\],\:,\|,\.,\?,\<,\>]{8,32})$/;
	if(f.SNMP_USER_SAFE.value == 0)	return true;
	else if(f.SNMP_USER_SAFE.value == 1)
	{
		string = f.SNMP_USER_PASSWORD.value;
		if(-1 == string.search(reg))
		{
			alert("认证密码不能输入非法字符:\\,\/,\",\',\;,#,空字符串,空格以及中文字符,并确保其长度范围！");
			return false;		
		}
		
		if (!password_match(f.SNMP_USER_PASSWORD.value, f.SNMP_USER_PASSWORD_CON.value))
		{
			alert('认证密码不匹配!');
			return false;	
		}
	}
	else if(f.SNMP_USER_SAFE.value == 2)
	{
		string = f.SNMP_USER_PASSWORD.value;
		if(-1 == string.search(reg))
		{
			alert("认证密码不能输入非法字符:\\,\/,\",\',\;,#,空字符串,空格以及中文字符,并确保其长度范围！");
			return false;		
		}
		
		if (!password_match(f.SNMP_USER_PASSWORD.value, f.SNMP_USER_PASSWORD_CON.value))
		{
			alert('认证密码不匹配!');
			return false;	
		}
		
		string = f.SNMP_USER_ENPASSWORD.value;
		if(-1 == string.search(reg))
		{
			alert("加密密码不能输入非法字符:\\,\/,\",\',\;,#,空字符串,空格以及中文字符,并确保其长度范围！");
			return false;		
		}
		
		if (!password_match(f.SNMP_USER_ENPASSWORD.value, f.SNMP_USER_ENPASSWORD_EN.value))
		{
			alert('加密密码不匹配!');
			return;		
		}
	}
	 return true;
}
function find_snmp_add_user_which_num()
{	
	var user_index = 0;
	for(user_index=0; user_index < MAX_USER_COUNT; user_index++)
	{
		if(!snmp_user_name[user_index])
		{
			return user_index;
		}
	}
}
function init()
{
	var f=document.forms[0];
	f.SNMP_USER_NAME.value = '';
	get_build(MAX_USER_COUNT);
	selegroup(0);
	selet_password_mode(0,0);
}

function community_do_diffCfg()
{
	 var after_add_num = 0;
	 var f=document.forms["system_user"];
	 if(snmp_user_num >= 4)
	 {
		alert("最多只支持创建4个用户！");
		return false;
	 }
	 if(!f.SNMP_USER_INGROUP.value)
	 {
		alert("没有选择组，不能创建用户！");
		return false;
	 }
	var string = f.SNMP_USER_NAME.value;
	for(num=0; num< MAX_USER_COUNT; num++)
	{	
		if(snmp_user_name[num])
		{
			if(string == snmp_user_name[num])
			{
				alert("用户名" +string+"已经存在!");
				return false;	
			}
		}
	}
		after_add_count = ++snmp_user_num;
		diffCfg("SNMP_COUNT", "snmp_count", after_add_count); 
		snmp_user_num--;
		var which_num = find_snmp_add_user_which_num();
		
		diffCfg("SNMP_ADD_GROUP_WHICH_NUM", "snmp_add_group_which_num", which_num);  		
		diffCfg("SNMP_USER_NAME", "snmp_user_name", f.SNMP_USER_NAME.value);
		diffCfg("SNMP_USER_SAFE", "snmp_user_security", f.SNMP_USER_SAFE.value);
		diffCfg("SNMP_USER_INGROUP", "snmp_user_ingroup", f.SNMP_USER_INGROUP.value);
		if(f.SNMP_USER_SAFE.value==0)
		{
			diffCfg("SNMP_USER_PASSWORD", "snmp_user_password", "");
			diffCfg("SNMP_USER_ENPASSWORD", "snmp_user_enpassword", "");			
		}
		else if(f.SNMP_USER_SAFE.value==1)	
		{		
			diffCfg("SNMP_USER_PASSWORD", "snmp_user_password", f.SNMP_USER_PASSWORD.value);
			diffCfg("SNMP_USER_ENPASSWORD", "snmp_user_enpassword", "");
		}
		else if(f.SNMP_USER_SAFE.value==2)
		{
			diffCfg("SNMP_USER_PASSWORD", "snmp_user_password", f.SNMP_USER_PASSWORD.value);
			diffCfg("SNMP_USER_ENPASSWORD", "snmp_user_enpassword", f.SNMP_USER_ENPASSWORD.value);
		}
		

}

function apply_all(type, comm_index)
{	
	var f=document.forms["system_user"];
	if(0 == type)  /*确定*/
	{	
		if (!check_all_input())return;	
		if(false == community_do_diffCfg())
		{
			return false;
		}
	
		subForm(f,'goform/command','SNMP_USER','system_snmp_user.asp');
	}
	else  		/*删除*/
	{	
		diffCfg("SNMP_DEL_USER_WHICHNUM", "snmp_del_user_which_num", comm_index);
		subForm(f,'goform/command','SNMP_USER', 'system_snmp_user.asp');
	}	
}
 
</script>
</head>

<body onload=init()>
<script>pageHead(webVars);</script>
<SCRIPT language=JavaScript>buildNavigatorTab(system_snmp, 4)</SCRIPT>
<form name=system_user action=goform/command method=post>

<table width=100% border=0 align=center cellpadding=0 cellspacing=0
	class=box_tn>
	<tr>
		<td>
		<table width=100% border=0 align=center cellpadding=5 cellspacing=1
			bgcolor="#FFFFFF">
		<tr>
		<td width=100% class=greybluebg colspan=2>新建用户</td>
		</tr>
		<tr>
		<td width=30% class=bgblue>用户名</td>
 		<td width=70% class=bggrey><input type="text" size="32"  name="SNMP_USER_NAME" id="SNMP_USER_NAME" maxlength="32" >(1~32字符)
		</TD> 
		</tr>	
		<tr>	
		<tr>
			<td  class=bgblue>安全级别</td>
 			<td  class=bggrey><select name="SNMP_USER_SAFE" onChange="selet_security()" style="WIDTH: 228px">
			<option value=0> 不认证不加密</option>
			<option value=1>只认证不加密</option> 
			<option value=2>既认证又加密</option>
			</select>
			</td>
		</tr>	
		</table>
		<div id="selet_groups"></div>
		
		<div id="selet_passwordmode"></div>	
		
		<tr><td >
			<table width="100%" cellSpacing=1 cellPadding=1 >
			<tr  width=100% class=greybluebg colspan=2>
			<td width=20% align='center'><font size=3>用户名 </font></td>
			<td width=20% align='center'><font size=3>组名 </font></td>
			<td width=20% align='center'><font size=3>安全级别 </font></td>
			<td width=15% align='center'><font size=3>认证模式 </font></td>
			<td width=15% align='center'><font size=3>加密模式 </font></td>
			<td width=10% align="center"><font size=3>删除</font></td>						
		</tr>
		<script language="JavaScript">
			var comm_index;
			if(0 != snmp_user_num)
			{	for(comm_index=0; comm_index<MAX_USER_COUNT; comm_index++)
				{	
					if(snmp_user_name[comm_index])
					{							
						document.write('<tr  width=100% class=bggrey>');
						document.write('<td width=20% align="center">' + snmp_user_name[comm_index] + '</td> ');
						document.write('<td width=20% align="center">' + snmp_group_name[comm_index] + '</td> ');
						document.write('<td width=20% align="center">' + snmp_user_security[comm_index] + '</td> ');
						document.write('<td width=15% align="center">MD5</td> ');
						document.write('<td width=15% align="center">DE856</td> ');						
						document.write('<td width=10% align="center"><input type=button value="删除" onclick=apply_all(1,' +comm_index +') ></td></tr>');				
					}
				}
			}
		</script>
			</table>
			<td><input type="hidden" name="SNMP_DEL_USER_WHICHNUM" value="0"></td>
			<td> <input type="hidden" name="SNMP_ADD_GROUP_WHICH_NUM" value="0"> </td>
		</td></tr>
	</td>
	</tr>
</table>
<p>
<input type=button value="确认" onclick=apply_all(0,0) >
<input type=button value="取消" onclick=init() >
</p>
</form>

<script>pageTail();</script>
</body>
</html>
