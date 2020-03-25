#lang sicp
(#%require sicp-pict)

(define (below painter1 painter2)
  (let ((split-point (make-vect 0.0 0.5)))
    (let ((paint-down
           ((transform-painter 
             (make-vect 0.0 0.0)
             (make-vect 1.0 0.0)
             split-point)
            painter1))
          (paint-up
           ((transform-painter
             split-point
             (make-vect 1.0 0.5)
             (make-vect 0.0 1.0))
            painter2)))
      (lambda (frame)
        (paint-down frame)
        (paint-up frame)))))

(define (below1 painter1 painter2)
  (rotate90 (beside (rotate270 painter1)
                    (rotate270 painter2))))
      

(define (polyline vectors)
  (if (null? (cdr vectors))
      nil
      (cons (make-segment (car vectors)
                          (cadr vectors))
            (polyline (cdr vectors)))))

(define wave
  (segments->painter
   (append (polyline (list (make-vect 0 0.87)
                           (make-vect 0.13 (/ 5.5 8))
                           (make-vect 0.25 0.75)
                           (make-vect (/ 3 8) 0.75)
                           (make-vect (/ 2.6 8) (/ 7.6 8))
                           (make-vect (/ 3 8) 1)))
           (polyline (list (make-vect (/ 5 8) 1)
                           (make-vect (/ 5.4 8) (/ 7.6 8))
                           (make-vect (/ 5 8) 0.75)
                           (make-vect 0.75 0.75)
                           (make-vect 1 (/ 3.5 8))))
           (polyline (list (make-vect 1 0.25)
                           (make-vect (/ 5 8) 0.5)
                           (make-vect 0.75 0)))
           (polyline (list (make-vect (/ 4.6 8) 0)
                           (make-vect 0.5 0.25)
                           (make-vect (/ 3.4 8) 0)))
           (polyline (list (make-vect 0.25 0)
                           (make-vect (/ 3 8) 0.5)
                           (make-vect (/ 2.15 8) (/ 5 8))
                           (make-vect (/ 1 8) (/ 3 8))
                           (make-vect 0 (/ 5 8)))))))