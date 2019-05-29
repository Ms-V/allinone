param($win7,$win10ent,$win10pro,$office10,$office13,$office16)
$0s_bit = (Get-WmiObject Win32_OperatingSystem).osarchitecture
$ver = Get-WmiObject -Class Win32_OperatingSystem | Select-Object -ExpandProperty Caption
if($ver -like "*Windows 10*" -and ($ver -like "*Professional*" -or "*Pro*"))
{
    Write-Host "The os is "$ver "AKA Win10 pro.start inject key"
    slmgr -ipk $win10pro
    start-sleep -s 5
    Write-Host "Start activation"
    slmgr -ato
}
elseif($ver -like "*Windows 10*" -and $ver -like "*Enterprise*")
{
    Write-Host "The os is "$ver "AKA Win10 Ent.start inject key"
    slmgr -ipk $win10ent
    start-sleep -s 5
    Write-Host "Start activation"
    slmgr -ato
}
elseif($ver -like "*Windows 7*")
{
    Write-Host "The os is "$ver "AKA Win7.start inject key"
    slmgr -ipk $win7
    start-sleep -s 5
    Write-Host "Start activation"
    slmgr -ato
}
else
{
    Write-Host "Error"
}
if($0s_bit[0] -eq '6')
{
    
    if((Test-Path 'c:\Program Files\Microsoft Office\Office16\*' -include OSPP.VBS) -eq $true)
    {
        Write-Host "The office is office2016 inject key.The bit is"$0s_bit
        cscript 'c:\Program Files\Microsoft Office\Office16\OSPP.VBS' /inpkey:$office16
        start-sleep -s 5
        Write-Host "Start activation"
        cscript 'c:\Program Files\Microsoft Office\Office16\OSPP.VBS' /act
    }
    elseif((Test-Path 'c:\Program Files\Microsoft Office\Office15\*' -include OSPP.VBS) -eq $true)
    {
        Write-Host "The office is office2013 inject key.The bit is"$0s_bit
        cscript 'c:\Program Files\Microsoft Office\Office15\OSPP.VBS' /inpkey:$office13
        start-sleep -s 5
        Write-Host "Start activation"
        cscript 'c:\Program Files\Microsoft Office\Office15\OSPP.VBS' /act
    }
    elseif((Test-Path 'c:\Program Files\Microsoft Office\Office14\*' -include OSPP.VBS) -eq $true)
    {
        Write-Host "The office is office2010 inject key.The bit is"$0s_bit
        cscript 'c:\Program Files\Microsoft Office\Office14\OSPP.VBS' /inpkey:$office10
        start-sleep -s 5
        Write-Host "Start activation"
        cscript 'c:\Program Files\Microsoft Office\Office14\OSPP.VBS' /act
    }
    elseif((Test-Path 'c:\Program Files (x86)\Microsoft Office\Office16\*' -exclude OSPP.VBS) -eq $true)
    {
        Write-Host "The office is office2016 inject key.The bit is"$0s_bit
        cscript 'c:\Program Files (x86)\Microsoft Office\Office16\OSPP.VBS' /inpkey:$office16
        start-sleep -s 5
        Write-Host "Start activation"
        cscript 'c:\Program Files (x86)\Microsoft Office\Office16\OSPP.VBS' /act
    }
    elseif((Test-Path 'c:\Program Files (x86)\Microsoft Office\Office15\*' -exclude OSPP.VBS) -eq $true)
    {
        Write-Host "The office is office2013 inject key.The bit is"$0s_bit
        cscript 'c:\Program Files (x86)\Microsoft Office\Office15\OSPP.VBS' /inpkey:$office13
        start-sleep -s 5
        Write-Host "Start activation"
        cscript 'c:\Program Files (x86)\Microsoft Office\Office15\OSPP.VBS' /act
    }
    elseif((Test-Path 'c:\Program Files (x86)\Microsoft Office\Office14\*' -exclude OSPP.VBS) -eq $true)
    {
        Write-Host "The office is office2010 inject key.The bit is"$0s_bit
        cscript 'c:\Program Files (x86)\Microsoft Office\Office14\OSPP.VBS' /inpkey:$office10
        start-sleep -s 5
        Write-Host "Start activation"
        cscript 'c:\Program Files (x86)\Microsoft Office\Office14\OSPP.VBS' /act
    }
    else
    {
        Write-Host "Error! office version not correct or can't find office in 64Bit os,activation failure."
    }
}
elseif($0s_bit[0] -eq '3')
{
       if((Test-Path 'c:\Program Files\Microsoft Office\Office16\*' -include OSPP.VBS) -eq $true)
    {
        Write-Host "The office is office2016 inject key.The bit is"$0s_bit
        cscript 'c:\Program Files\Microsoft Office\Office16\OSPP.VBS' /inpkey:$office16
        start-sleep -s 5
        Write-Host "Start activation"
        cscript 'c:\Program Files\Microsoft Office\Office16\OSPP.VBS' /act
    }
    elseif((Test-Path 'c:\Program Files\Microsoft Office\Office15\*' -include OSPP.VBS) -eq $true)
    {
        Write-Host "The office is office2013 inject key.The bit is"$0s_bit
        cscript 'c:\Program Files\Microsoft Office\Office15\OSPP.VBS' /inpkey:$office13
        start-sleep -s 5
        Write-Host "Start activation"
        cscript 'c:\Program Files\Microsoft Office\Office15\OSPP.VBS' /act
    }
    elseif((Test-Path 'c:\Program Files\Microsoft Office\Office14\*' -include OSPP.VBS) -eq $true)
    {
        Write-Host "The office is office2010 inject key.The bit is"$0s_bit
        cscript 'c:\Program Files\Microsoft Office\Office14\OSPP.VBS' /inpkey:$office10
        start-sleep -s 5
        Write-Host "Start activation"
        cscript 'c:\Program Files\Microsoft Office\Office14\OSPP.VBS' /act
    }
    else
    {
        Write-Host "Error! office version not correct or can't find office in 32Bit os,activation failure."
    }
}
else
{
    Write-Host "Error! office version not correct,activation failure.(Beasce can't find bit of os)"
}