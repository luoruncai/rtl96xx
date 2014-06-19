<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<!--系统默认模板-->
<HTML>
<HEAD>
<TITLE>日常应用</TITLE>
<META http-equiv=pragma content=no-cache>
<META http-equiv=cache-control content="no-cache, must-revalidate">
<META http-equiv=content-type content="text/html; charset=gbk">
<META http-equiv=content-script-type content=text/javascript>
<!--系统公共css-->
<STYLE type=text/css>
@import url(/style/default.css);
</STYLE>
<!--系统公共脚本-->
<SCRIPT language="javascript" src="common.js"></SCRIPT>
<SCRIPT language="javascript" type="text/javascript">


/********************************************************************
**          on document load
********************************************************************/
function on_init()
{

}

/********************************************************************
**          on document submit
********************************************************************/
function on_submit() 
{
	if((form.proxy0_addr.value == "") || !sji_checkvip(form.proxy0_addr.value))
	{
		alert("主用SIP Proxy IP地址错误！");
		return false;
	}
	if((form.proxy0_port.value == "") || !sji_checkdigitrange(form.proxy0_port.value, 1, 65535))
	{
		alert("主用SIP Proxy请输入合法的端口号！");
		return false;
	}

	if((form.proxy1_addr.value == "") || !sji_checkvip(form.proxy1_addr.value))
	{
		alert("备用SIP Proxy IP地址错误！");
		return false;
	}
	if((form.proxy1_port.value == "") || !sji_checkdigitrange(form.proxy1_port.value, 1, 65535))
	{
		alert("备用SIP Proxy请输入合法的端口号！");
		return false;
	}

	if((form.login_id.value == "") || !sji_checkusername(form.login_id.value, 1, 32))
	{
		alert("请输入合法的用户名！");
		return false;
	}
	
	if((form.password.value == "") || !sji_checkpswnor(form.password.value, 1, 32))
	{
		alert("请输入合法的密码！");
		return false;
	}

	if( (form.preced0.value == form.preced1.value) || (form.preced0.value == form.preced2.value) || (form.preced0.value == form.preced3.value) ||
	    (form.preced1.value == form.preced2.value) || (form.preced1.value == form.preced3.value) || (form.preced2.value == form.preced3.value) )
	{
			alert("宽带电话高级设置错误，相同设定在不同优先顺位!");
			return false;
	}
	
	form.submit();
	//submit();
}
</SCRIPT>
</HEAD>

<!-------------------------------------------------------------------------------------->
<!--主页代码-->
<body topmargin="0" leftmargin="0" marginwidth="0" marginheight="0" alink="#000000" link="#000000" vlink="#000000">
	<blockquote>
		<DIV align="left" style="padding-left:20px; padding-top:5px">
			<form id="form" action=/boaform/admin/voip_e8c_set method=POST>
				<b>主用SIP Proxy<br>
				<table border="0" cellpadding="0" cellspacing="0" width="500">
					<tr><td width="200px">地址:</td><td><input name="proxy0_addr" size="16" maxlength="32" type="text" style="width:140px" value="<% voip_e8c_get("proxy0_addr"); %>"></td></tr>
					<tr><td>端口号:</td><td><input name="proxy0_port" size="16" maxlength="32" style="width:140px" value="<% voip_e8c_get("proxy0_port"); %>"></td></tr>
				</table>
				<br>

				<b>备用SIP Proxy<br>
				<table border="0" cellpadding="0" cellspacing="0" width="500">
					<tr><td width="200px">地址:</td><td><input name="proxy1_addr" size="16" maxlength="32" type="text" style="width:140px" value="<% voip_e8c_get("proxy1_addr"); %>"></td></tr>
					<tr><td>端口号:</td><td><input name="proxy1_port" size="16" maxlength="32" style="width:140px" value="<% voip_e8c_get("proxy1_port"); %>"></td></tr>
				</table>
				<br>

				<b>账号<br>
				<table border="0" cellpadding="0" cellspacing="0" width="500">
					<tr><td width="200px">启用</td><td><input name="account_enable" type="checkbox" value="enable" <% voip_e8c_get("account_enable"); %>></td></tr>
					<tr><td>用户号码:</td><td><input name="login_id" size="16" maxlength="32" style="width:140px" value="<% voip_e8c_get("login_id"); %>"></td></tr>
					<tr><td>用户密码:</td><td><input name="password" size="16" maxlength="32" type="password" style="width:140px" value="<% voip_e8c_get("password"); %>"></td></tr>
				</table>
				<br>

				<b>宽带电话高级设置<br>
				<table border="0" cellpadding="0" cellspacing="0" width="500">
					<% voip_e8c_get("e8c_codec"); %>
				</table>
				<br>

				<table border="0" cellpadding="0" cellspacing="0" width="500">
					<tr><td width="200px">回声抑制设置</td><td><input type="checkbox" name="echo_cancellation" value="1" <% voip_e8c_get("useLec"); %>></td></tr>
				</table>
				<br>

				<input type="button" class="button" name="btnDown" value="保存/应用" onClick="on_submit()">
				<input type="hidden" name="submit-url" value="">
			</form>
		</DIV>
	</blockquote>
</body>
<%addHttpNoCache();%>
</html>
