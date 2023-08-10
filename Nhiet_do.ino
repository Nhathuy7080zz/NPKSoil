void nhietdo()
{
  Serial.println("Humi2 Value:       ");
  /*Read value Temp1*/
  result2 = node2.readHoldingRegisters(0x0000, 2);
  // do something with data if read is successful
  if (result2 == node2.ku8MBSuccess)
  {
    data2[0] = node2.receive();
    // Humi2 = round((float(data2[0])/10)*1.06);
    Humi2 = round((float(data2[0]) / 10) * 1.06);
    float tempp = round((float(data2[0]) / 10));
    Humi2 = map(tempp, 0, 70, 0, 100);
    if (Humi2 > 100) {
      Humi2 = 100;
    }
    Serial.print("Temp1 Value: ");
    Serial.print(Temp2);
    Serial.println("%RH");
  }
  delay(00);
  /*Read value Humi2*/
  result2 = node2.readHoldingRegisters(0x0001, 2);
  // do something with data if read is successful
  if (result2 == node2.ku8MBSuccess)
  {
    data2[0] = node2.receive();
    Temp2 = (float(data2[0]) / 10);
    Serial.print("DATA NHIET DO ");
    Serial.print(Humi2);
    Serial.print(char(223));
    Serial.println("C");
  }
  delay(500);
}
