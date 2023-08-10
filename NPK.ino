void npk()
{
  Serial.println("DATA NPK      ");
  /*Read value Nito*/
  result3 = node3.readHoldingRegisters(0x001E, 2);
  // do something with data if read is successful
  if (result3 == node3.ku8MBSuccess)
  {
    data3[0] = node3.receive();
    Nito = float(data3[0]);
    Serial.print("Nito Value: ");
    Serial.print(Nito);
    Serial.println("mg/Kg");
  }
  delay(500);
  /*Read value Photpho*/
  result3 = node3.readHoldingRegisters(0x001F, 2);
  // do something with data if read is successful
  if (result3 == node3.ku8MBSuccess)
  {
    data3[0] = node3.receive();
    Photpho = float(data3[0]);
    Serial.print("Photpho Value: ");
    Serial.print(Photpho);
    Serial.println("mg/Kg");
  }
  delay(500);

  /*Read value Kali*/
  result3 = node3.readHoldingRegisters(0x0020, 2);
  // do something with data if read is successful
  if (result3 == node3.ku8MBSuccess)
  {
    data3[0] = node3.receive();
    Kali = float(data3[0]);
    Serial.print("Kali Value: ");
    Serial.print(Kali);
    Serial.println("mg/Kg");
  }
  delay(00);
}
