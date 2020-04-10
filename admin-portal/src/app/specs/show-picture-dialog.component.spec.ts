import { async, ComponentFixture, TestBed } from "@angular/core/testing";

import { ShowPictureDialogComponent } from "../show-picture-dialog/show-picture-dialog.component";

describe("ShowPictureDialogComponent", () => {
  let component: ShowPictureDialogComponent;
  let fixture: ComponentFixture<ShowPictureDialogComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ShowPictureDialogComponent]
    }).compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(ShowPictureDialogComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it("should create", () => {
    expect(component).toBeTruthy();
  });
});
